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
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.IPath;
import org.eclipse.core.runtime.Path;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;
import org.w3c.dom.Text;
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
							e.printStackTrace();
						} catch (IOException e) {
							e.printStackTrace();
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

		IPath ctxPath = new Path(new String(
				((IScriptFileDeclaration) _inferenceFile).getFileName()));

		IPath pw = ResourcesPlugin.getWorkspace().getRoot().getLocation();
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
		res.updatePositions(uiNameExpression.sourceStart(),
				uiNameExpression.sourceEnd());

		InferredType resUi = this.addType(InferredType.OBJECT_LITERAL_NAME, true);
		//resUi.isAnonymous=true;
		//resUi.isObjectLiteral=true;
		//resUi.superClass = ObjectType;
		
		// resUi.isAnonymous = true;
		resUi.updatePositions(uiNameExpression.sourceStart(),
				uiNameExpression.sourceEnd());

		// прототип
		nodes = doc.getElementsByTagName("widget");
		if (nodes.getLength() < 1) {
			return res;
		}
		Element el = (Element) nodes.item(0);
		res.superClass = this.addType(el.getAttribute("class").toCharArray(),
				false);

		// дочерние виджеты
		// уже nodes = doc.getElementsByTagName("widget");
		for (int i = 0; i < nodes.getLength(); i++) {
			el = (Element) nodes.item(i);

			String name = el.getAttribute("name");
			String cls = el.getAttribute("class");

			if (name != null && cls != null) {
				InferredAttribute a = new InferredAttribute(name.toCharArray(),
						addType(cls.toCharArray(), false),
						uiNameExpression.sourceStart(),
						uiNameExpression.sourceEnd());
				a.type = a.inType;
				resUi.addAttribute(a);
			}
		}

		InferredAttribute ui = new InferredAttribute("ui".toCharArray(), resUi,
				uiNameExpression.sourceStart(), uiNameExpression.sourceEnd());
		ui.type = ui.inType;
		res.addAttribute(ui);

		return res;
	}
}
