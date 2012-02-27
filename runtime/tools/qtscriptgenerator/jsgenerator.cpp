/****************************************************************************
**
** Copyright (C) 2008-2009 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Script Generator project on Qt Labs.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "jsgenerator.h"
#include "fileout.h"
#include <iostream>

JsGenerator::JsGenerator()
{
}

QString JsGenerator::fileNameForClass(const AbstractMetaClass *meta_class) const
{
    return QString::fromLatin1("%0.js").arg(meta_class->name().toLower());
}

QString JsGenerator::subDirectoryForClass(const AbstractMetaClass *) const
{
    return QString::fromLatin1("js");
}

static void writeDocumentHeader(QTextStream &s, const QString &title)
{
    s << "/*" << endl;
    s << title;
    s << "*/" << endl;
    s << endl;
    s << endl;
}

static void writeDocumentFooter(QTextStream &s)
{
}

static bool classLessThan(const AbstractMetaClass *c1, const AbstractMetaClass *c2)
{
    return c1->name() < c2->name();
}

bool JsGenerator::shouldGenerate(const AbstractMetaClass *meta_class) const
{
    uint cg = meta_class->typeEntry()->codeGeneration();
    return (cg & TypeEntry::GenerateCode) != 0;
}

void JsGenerator::generate()
{
    Generator::generate();
}

static bool shouldIgnoreEnum(const AbstractMetaEnum *enom)
{
    return !enom->wasPublic() || (enom->name() == "enum_1");
}

// in classgenerator.cpp
void findPrototypeAndStaticFunctions(
    const AbstractMetaClass *meta_class,
    QMap<QString, AbstractMetaFunctionList> &nameToPrototypeFunctions,
    QMap<QString, AbstractMetaFunctionList> &nameToStaticFunctions);
QList<int> uniqueEnumValueIndexes(const AbstractMetaEnumValueList &values);

static void writeFunction(QTextStream &s, const AbstractMetaFunction *fun, int idx, bool isCtor, QString scope="")
{
    //s << "<li><div class=\"fn\"/><b>" << fun->targetLangSignature() << "</b></li>" << endl;

    //name
    s << "/**" << endl;
    s << "* @name " << fun->name(); if(idx) s << "^" << idx; s << endl;

    //ctor or func
    s << "* @" << (isCtor?"constructor":"function") << endl;

    if(!scope.isEmpty())
    {
        s << "* @memberOf " << scope << endl;
    }

    //params
    AbstractMetaArgumentList al = fun->arguments();
    for(int i(0); i<al.size(); i++)
    {
        AbstractMetaArgument *a = al[i];
        s << "* @param {" << a->type()->name() << "} " << a->argumentName() << endl;
    }

    //retval
    if(!isCtor)
    {
        s << "* @returns {" << (fun->type()?fun->type()->name():"void") << "}" << endl;
    }

    s << "*/" << endl;

    //js
    if(scope.isEmpty())
    {
        s << "var " << fun->name() << " = function(";
    }
    else
    {
        s << scope << "." << fun->name() << " = function(";
    }
    for(int i(0); i<al.size(); i++)
    {
        AbstractMetaArgument *a = al[i];
        if(i) s << ", ";
        s << a->argumentName();
    }
    s << "){};" << endl;

    s << endl;
}

void JsGenerator::write(QTextStream &s, const AbstractMetaClass *meta_class)
{
/*
    QString title = meta_class->name();
    title.append(" ");
    if (meta_class->isNamespace())
        title.append("Namespace");
    else
        title.append("Class");
    title.append(" Reference");
    writeDocumentHeader(s, title);

    s << "<h1 align=\"center\">" << title << "</h1>" << endl;

    s << "<h3 align=\"center\">[<a href=\"";
    s << meta_class->package().split(".").join("_") << ".html";
    s << "\">";
    s << meta_class->package();
    s << "</a> package]</h3>" << endl;
*/
    s << "/**" << endl;
    s << "* @" << (meta_class->isNamespace()?"namespace":"class") << " " << meta_class->name() << " from package " << meta_class->package() << endl;






/*
    if (meta_class->baseClass()) {
        s << "<p>Inherits <a href=\"" << fileNameForClass(meta_class->baseClass()) << "\">"
          << meta_class->baseClass()->name() << "</a>.</p>" << endl;
    } else if (!meta_class->interfaces().isEmpty()) {
        AbstractMetaClass *iface = meta_class->interfaces().first();
        AbstractMetaClass *impl = iface->primaryInterfaceImplementor();
        if (impl != meta_class) {
            s << "<p>Inherits <a href=\"" << fileNameForClass(impl) << "\">"
              << impl->name() << "</a>.</p>" << endl;
        }
    }
*/
    if (meta_class->baseClass()) {
        s << "* @inherits " << meta_class->baseClass()->name() << endl;
    } else if (!meta_class->interfaces().isEmpty()) {
        AbstractMetaClass *iface = meta_class->interfaces().first();
        AbstractMetaClass *impl = iface->primaryInterfaceImplementor();
        if (impl != meta_class) {
            s << "* @inherits " << impl->name() << endl;
        }
    }
    s << "*/" << endl;
    s << "var " << meta_class->name() << " = {};" << endl;
    s << endl;


    AbstractMetaFunctionList ctors;
    ctors = meta_class->queryFunctions(AbstractMetaClass::Constructors
                                       | AbstractMetaClass::WasPublic
                                       | AbstractMetaClass::NotRemovedFromTargetLang);
    QMap<QString, AbstractMetaFunctionList> nameToPrototypeFunctions;
    QMap<QString, AbstractMetaFunctionList> nameToStaticFunctions;
    findPrototypeAndStaticFunctions(meta_class, nameToPrototypeFunctions, nameToStaticFunctions);

/*
    s << "<h3>Constructor</h3>" << endl;
    if (!ctors.isEmpty()) {
        s << "<ul>" << endl;
        for (int i = 0; i < ctors.size(); ++i) {
            writeFunction(s, ctors.at(i));
        }
        s << "</ul>" << endl;
    } else {
        s << "<p>This class has no public constructors. Calling the constructor function will cause a TypeError.</p>";
    }
*/
    if (!ctors.isEmpty()) {
        for (int i = 0; i < ctors.size(); ++i) {
            writeFunction(s, ctors.at(i), i, true);
        }
    } else {
    }




/*
    s << "<h3>Constructor Properties</h3>" << endl;
    s << "<ul>" << endl;
    s << "<li><b>prototype</b>: The " << meta_class->name() << " prototype object</li>" << endl;
    if (!nameToStaticFunctions.isEmpty()) {
        QMap<QString, AbstractMetaFunctionList>::const_iterator it;
        int i(0);
        for (it = nameToStaticFunctions.constBegin(); it != nameToStaticFunctions.constEnd(); ++it,i++) {
            writeFunction(s, it.value().first(), i, false);
        }
    }
*/



    if (!nameToStaticFunctions.isEmpty()) {
        QMap<QString, AbstractMetaFunctionList>::const_iterator it;
        int i(0);
        for (it = nameToStaticFunctions.constBegin(); it != nameToStaticFunctions.constEnd(); ++it,i++) {
            writeFunction(s, it.value().first(), 0, false, meta_class->name());
        }
    }

/*
    {
        AbstractMetaEnumList enums = meta_class->enums();
        for (int i = 0; i < enums.size(); ++i) {
            const AbstractMetaEnum *enom = enums.at(i);
            if (shouldIgnoreEnum(enom))
                continue;
            AbstractMetaEnumValueList values = enom->values();
            QList<int> indexes = uniqueEnumValueIndexes(values);
            for (int j = 0; j < indexes.size(); ++j) {
                AbstractMetaEnumValue *val = values.at(indexes.at(j));
                s << "<li><b>" << val->name();
                if (!val->stringValue().isEmpty())
                    s << " = " << val->stringValue();
                s << "</b></li>" << endl;
            }
            s << "<li><b>" << enom->name() << "( value )</b></li>" << endl;
            FlagsTypeEntry *flags = enom->typeEntry()->flags();
            if (flags)
                s << "<li><b>" << flags->flagsName() << "( value1, value2, ... )</b></li>" << endl;
        }
    }
    s << "</ul>" << endl;
*/

    {
        AbstractMetaEnumList enums = meta_class->enums();
        for (int i = 0; i < enums.size(); ++i)
        {
            const AbstractMetaEnum *enom = enums.at(i);
            if (shouldIgnoreEnum(enom))
                continue;

            FlagsTypeEntry *flags = enom->typeEntry()->flags();

            AbstractMetaEnumValueList values = enom->values();
            QList<int> indexes = uniqueEnumValueIndexes(values);
            for (int j = 0; j < indexes.size(); ++j)
            {
                AbstractMetaEnumValue *val = values.at(indexes.at(j));
                s << "/**" << endl;
                s << "* @constant" << endl;
                s << "* @memberOf " << meta_class->name() << endl;
                s << "* @name " << val->name() << endl;

                if(flags)
                {
                    s << "* @see " << meta_class->name() << "#" << flags->flagsName() << endl;
                }
                s << "* @see " << meta_class->name() << "#" << enom->name() << endl;
                s << "*/" << endl;

                s << meta_class->name() << "." << val->name();
                if (!val->stringValue().isEmpty())
                    s << " = " << val->stringValue();
                s << ";" << endl;
            }
            if(indexes.size())
            {
                s << endl;
            }

            s << "/**" << endl;
            s << "* @constructor " << endl;
            s << "* @memberOf " << meta_class->name() << endl;
            s << "* @name " << enom->name() << endl;
            s << "*/" << endl;
            s << meta_class->name() << "." << enom->name() << " = function(value){};" << endl;
            s << endl;

            if (flags)
            {
                s << "/**" << endl;
                s << "* @constructor " << endl;
                s << "* @memberOf " << meta_class->name() << endl;
                s << "* @name " << flags->flagsName() << endl;
                s << "*/" << endl;
                s << meta_class->name() << "." <<  flags->flagsName() << " = function(value1, value2 /*, ...*/){};" << endl;
            }
            s << endl;

            s << endl;
        }
    }


//     s << "/**" << endl;
//     s << "* @type {Object} " << endl;
//     s << "* @memberOf " << meta_class->name() << endl;
//     if (!nameToPrototypeFunctions.isEmpty() && meta_class->baseClass())
//     {
//         s << "* @inherits " << meta_class->baseClass()->name() << ".prototype" << endl;
//     }
//     s << "* @name prototype" << endl;
//     s << "*/" << endl;
//     s << meta_class->name() << ".prototype = {};" << endl;
//     s << endl;

    if (!nameToPrototypeFunctions.isEmpty()) {

/*
        s << "<h3>Prototype Object Properties</h3>" << endl;
        if (meta_class->baseClass()) {
            s << "<p>The " << meta_class->name() << " prototype object inherits properties from the "
              << "<a href=\"" << fileNameForClass(meta_class->baseClass()) << "\">"
              << meta_class->baseClass()->name() << "</a> prototype object and "
              << "also has the following properties.</p>" << endl;
        }
        s << "<ul>" << endl;
        QMap<QString, AbstractMetaFunctionList>::const_iterator it;
        int i(0);
        for (it = nameToPrototypeFunctions.constBegin(); it != nameToPrototypeFunctions.constEnd(); ++it, i++) {
            writeFunction(s, it.value().first(), i, false);
        }
        s << "</ul>" << endl;
*/

        QMap<QString, AbstractMetaFunctionList>::const_iterator it;
        for (it = nameToPrototypeFunctions.constBegin(); it != nameToPrototypeFunctions.constEnd(); ++it)
        {
            writeFunction(s, it.value().first(), 0, false, meta_class->name()+".prototype");
        }

    }

/*
    if (!meta_class->isNamespace()) {
        s << "<h3>Instance Properties</h3>" << endl;
        {
            QList<QPropertySpec *> props = meta_class->propertySpecs();
            if (!props.isEmpty()) {
                s << "<p>" << meta_class->name() << " objects inherit properties from the "
                  << meta_class->name() << " prototype object and also have the following properties.</p>" << endl;
                s << "<ul>" << endl;
                for (int i = 0; i < props.size(); ++i) {
                    s << "<li><div class=\"fn\"/><b>" << props.at(i)->name() << "</b></li>" << endl;
                }
                s << "</ul>" << endl;
            } else {
                s << "<p>" << meta_class->name() << " objects have no special properties beyond those "
                  << "inherited from the " << meta_class->name() << " prototype object.</p>" << endl;
            }
        }
    }
*/
    if (!meta_class->isNamespace())
    {
        QList<QPropertySpec *> props = meta_class->propertySpecs();
        if (!props.isEmpty())
        {
            for (int i = 0; i < props.size(); ++i)
            {
                s << "/**" << endl;
                s << "* @name " << props.at(i)->name() << endl;
                s << "* @memberOf " << meta_class->name() << ".prototype" << endl;
                s << "* @type " << props.at(i)->type()->targetLangName() << endl;
                s << "*/" << endl;

                s << meta_class->name() << ".prototype." << props.at(i)->name() << ";" << endl;
                s << endl;
            }
            s << endl;
        }
    }

//    writeDocumentFooter(s);
}
