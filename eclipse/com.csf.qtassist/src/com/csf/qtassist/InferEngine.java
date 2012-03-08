/**
 * 
 */
package com.csf.qtassist;

import java.io.IOException;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

import org.eclipse.wst.jsdt.core.ast.IExpression;
import org.eclipse.wst.jsdt.core.ast.IFunctionCall;
import org.eclipse.wst.jsdt.core.ast.ILocalDeclaration;
import org.eclipse.wst.jsdt.core.ast.IScriptFileDeclaration;
import org.eclipse.wst.jsdt.core.ast.ISingleNameReference;
import org.eclipse.wst.jsdt.core.ast.IStringLiteral;
import org.eclipse.wst.jsdt.core.infer.IInferenceFile;
import org.eclipse.wst.jsdt.core.infer.InferOptions;
import org.eclipse.wst.jsdt.core.infer.InferredAttribute;
import org.eclipse.wst.jsdt.core.infer.InferredType;
import org.eclipse.core.resources.IContainer;
import org.eclipse.core.resources.IProject;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.IPath;
import org.eclipse.core.runtime.Path;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

/**
 * @author rekunkov
 * 
 */
public class InferEngine extends org.eclipse.wst.jsdt.core.infer.InferEngine {

	IInferenceFile _inferenceFile;

	/**
	 * 
	 */
	public InferEngine(InferrenceProvider inferenceProvider) {
		this.inferenceProvider = inferenceProvider;
	}

	/**
	 * @param inferOptions
	 */
	public InferEngine(InferOptions inferOptions) {
		super(inferOptions);
	}

	public void initializeOptions(InferOptions inferOptions) {

	}

	/**
	 * 
	 */
	public boolean visit(ILocalDeclaration localDeclaration) {

		IExpression init = localDeclaration.getInitialization();
		if (init instanceof IFunctionCall) {
			IFunctionCall functionCall = (IFunctionCall) localDeclaration
					.getInitialization();

			IExpression receiver = functionCall.getReceiver();

			if (receiver instanceof ISingleNameReference) {
				if ("uiLoader".equals(receiver.toString())
						&& "load"
								.equals(new String(functionCall.getSelector()))) {
					IExpression[] arguments = functionCall.getArguments();

					if (arguments.length >= 1) {
						try {
							localDeclaration.setInferredType(makeUiType(
									_inferenceFile, arguments[0]));
						} catch (SAXException e) {
							localDeclaration.setInferredType(addType("SAXException".toCharArray(), false));
							//e.printStackTrace();
						} catch (IOException e) {
							localDeclaration.setInferredType(addType("IOException".toCharArray(), false));
							//e.printStackTrace();
						}
					}
				}

			}
		}

		// localDeclaration.setInferredType(StringType);
		return super.visit(localDeclaration);
	}

	InferredType makeUiType(IInferenceFile inferenceFile,
			IExpression uiNameExpression) throws SAXException, IOException {
		if (!(uiNameExpression instanceof IStringLiteral)) {
			return VoidType;
		}
		String uiName = new String(((IStringLiteral) uiNameExpression).source());

		if (!(_inferenceFile instanceof IScriptFileDeclaration)) {
			return VoidType;
		}
		
		int srcStart = uiNameExpression.sourceStart();
		int srcEnd = uiNameExpression.sourceEnd();

		IPath ctxPath = new Path(new String(
				((IScriptFileDeclaration) _inferenceFile).getFileName()));
		
		if(2 > ctxPath.segmentCount())
		{
			return VoidType;
		}

		IProject proj = ResourcesPlugin.getWorkspace().getRoot().getProject(ctxPath.segment(0));
		if(proj == null)
		{
			return VoidType;
		}
		ctxPath = ctxPath.removeFirstSegments(1);
		
		IPath pw = proj.getLocation();
		ctxPath = pw.append(ctxPath);

		IPath uiPath = new Path(uiName);
		uiPath = ctxPath.removeLastSegments(1).append(uiPath);

		DocumentBuilder db;
		try {
			db = DocumentBuilderFactory.newInstance().newDocumentBuilder();
		} catch (ParserConfigurationException e) {
			e.printStackTrace();
			return VoidType;
		}
		Document doc = db.parse(uiPath.toFile());

		// класс компилируемого ui шаблона
		NodeList nodes = doc.getElementsByTagName("class");
		if (nodes.getLength() < 1) {
			return VoidType;
		}

		String s = nodes.item(0).getTextContent().trim();

		// класс компилируемого ui шаблона
		InferredType res = this.addType(s.toCharArray(), true);
		//InferredType res = createAnonymousType(s.toCharArray(), null);
		
		res.updatePositions(srcStart, srcEnd);

		InferredType resUi = this.addType((s+"_ui").toCharArray(), true);
		//InferredType resUi = createAnonymousType((s+"_ui").toCharArray(), null);
		
		resUi.updatePositions(srcStart, srcEnd);

		// прототип
		nodes = doc.getElementsByTagName("widget");
		if (nodes.getLength() < 1) {
			return res;
		}
		Element el = (Element) nodes.item(0);
		res.superClass = this.addType(el.getAttribute("class").toCharArray(), false);

		// дочерние виджеты, лайауты, экшины, экшн группы
		nodes = doc.getElementsByTagName("*");
		for (int i = 0; i < nodes.getLength(); i++) {
			el = (Element) nodes.item(i);

			String tagName = el.getTagName();
			if(	tagName == null || 
					(tagName != "widget" && tagName != "layout" && tagName != "action" && tagName != "actiongroup"))
			{
				continue;
			}
			String name = el.getAttribute("name");
			String cls = el.getAttribute("class");
			
			if(tagName == "action")
			{
				cls = "QAction";
			}
			else if(tagName == "actiongroup")
			{
				cls = "QActionGroup";
			}

			if (name != null && cls != null) {
				InferredAttribute a = new InferredAttribute(
						name.toCharArray(),
						addType(cls.toCharArray(), false),
						uiNameExpression.sourceStart(),
						uiNameExpression.sourceEnd());
				a.type = a.inType;
				a.nameStart = srcStart;
				a.initializationStart = srcStart;
				resUi.addAttribute(a);
			}
		}

		InferredAttribute ui = new InferredAttribute(
				"ui".toCharArray(), 
				resUi,
				uiNameExpression.sourceStart(), 
				uiNameExpression.sourceEnd());
		ui.type = ui.inType;
		ui.nameStart = srcStart;
		ui.initializationStart = srcStart;
		res.addAttribute(ui);

		return res;
	}
}
