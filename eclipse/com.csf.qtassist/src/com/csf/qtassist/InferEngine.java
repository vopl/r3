/**
 * 
 */
package com.csf.qtassist;

import org.eclipse.wst.jsdt.core.ast.IAbstractFunctionDeclaration;
import org.eclipse.wst.jsdt.core.ast.IExpression;
import org.eclipse.wst.jsdt.core.ast.IFunctionCall;
import org.eclipse.wst.jsdt.core.ast.IFunctionDeclaration;
import org.eclipse.wst.jsdt.core.ast.IJsDoc;
import org.eclipse.wst.jsdt.core.ast.ILocalDeclaration;
import org.eclipse.wst.jsdt.core.ast.ISingleNameReference;
import org.eclipse.wst.jsdt.core.infer.InferOptions;
import org.eclipse.wst.jsdt.core.infer.InferredMethod;
import org.eclipse.wst.jsdt.core.infer.InferredType;

/**
 * @author rekunkov
 *
 */
public class InferEngine extends org.eclipse.wst.jsdt.core.infer.InferEngine {

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

	/**
	 * 
	 */
	public boolean visit(ILocalDeclaration localDeclaration) {
		
		IExpression init = localDeclaration.getInitialization();
		if(init instanceof IFunctionCall)
		{
			IFunctionCall functionCall = (IFunctionCall)localDeclaration.getInitialization();
			
			IExpression receiver = functionCall.getReceiver();
			char[] selector = functionCall.getSelector();
			
			InferredType receiverType = this.getInferredType2(receiver);
			
			if(receiverType == null)
			{
				receiverType = inferredGlobal;
			}

			if(receiverType == null)
			{
				receiverType = GlobalType;
			}
			
			if(receiverType != null)
			{
				InferredMethod method = receiverType.findMethod(selector, null);
				
				if(method != null)
				{
					IFunctionDeclaration functionDeclaration = method.getFunctionDeclaration();
					InferredMethod inferredMethod = functionDeclaration.getInferredMethod();
				}

				IExpression[] arguments = functionCall.getArguments();
			}
			
			
			
			
			String tmp = "sdf";
			
		}
		
		//localDeclaration.setInferredType(StringType);
		return super.visit(localDeclaration);
	}
}
