/**
 * 
 */
package com.csf.qtassist;

import org.eclipse.wst.jsdt.core.ast.IExpression;
import org.eclipse.wst.jsdt.core.ast.IFunctionCall;
import org.eclipse.wst.jsdt.core.ast.IFunctionDeclaration;
import org.eclipse.wst.jsdt.core.ast.ILocalDeclaration;
import org.eclipse.wst.jsdt.core.ast.ISingleNameReference;
import org.eclipse.wst.jsdt.core.infer.IInferenceFile;
import org.eclipse.wst.jsdt.core.infer.InferOptions;
import org.eclipse.wst.jsdt.core.infer.InferredAttribute;
import org.eclipse.wst.jsdt.core.infer.InferredMethod;
import org.eclipse.wst.jsdt.core.infer.InferredType;

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

	public void initializeOptions(InferOptions inferOptions)
	{
		
	}
	
	/**
	 * 
	 */
	public boolean visit(ILocalDeclaration localDeclaration) {
		
		IExpression init = localDeclaration.getInitialization();
		if(init instanceof IFunctionCall)
		{
			IFunctionCall functionCall = (IFunctionCall)localDeclaration.getInitialization();
			
			IExpression receiver = functionCall.getReceiver();
			
			if(receiver instanceof ISingleNameReference)
			{
				if("uiLoader".equals(receiver.toString()) && "load".equals(new String(functionCall.getSelector())))
				{
					IExpression[] arguments = functionCall.getArguments();
					
					if(arguments.length >= 1)
					{
						localDeclaration.setInferredType(
								makeUiType(_inferenceFile, arguments[0]));
					}
				}
				
			}
		}
		
		//localDeclaration.setInferredType(StringType);
		return super.visit(localDeclaration);
	}
	
	InferredType makeUiType(IInferenceFile inferenceFile, IExpression uiName)
	{
		InferredType res = this.addType((new String("UiClassName")).toCharArray(), true);
		
		//res.isAnonymous=true;
		//res.isObjectLiteral=true;
		//res.superClass = ObjectType;
		
		res.updatePositions(uiName.sourceStart(), uiName.sourceEnd());

		//populateType( anonType, objLit , false);
		
		InferredAttribute a = new InferredAttribute(
				(new String("prop1")).toCharArray(), 
				addType((new String("MyClass")).toCharArray(), true), 
				uiName.sourceStart(), 
				uiName.sourceEnd());
		a.type = a.inType;
		res.addAttribute(a);
		
		a = new InferredAttribute(
				(new String("prop2")).toCharArray(), 
				BooleanType, 
				uiName.sourceStart(), 
				uiName.sourceEnd());
		a.type = a.inType;
		res.addAttribute(a);
		
		return res;
	}
}
