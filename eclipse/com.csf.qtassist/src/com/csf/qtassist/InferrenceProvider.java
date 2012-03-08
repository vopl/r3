/**
 * 
 */
package com.csf.qtassist;

import org.eclipse.wst.jsdt.core.infer.IInferEngine;
import org.eclipse.wst.jsdt.core.infer.IInferenceFile;
import org.eclipse.wst.jsdt.core.infer.RefactoringSupport;

/**
 * @author rekunkov
 *
 */
public class InferrenceProvider implements
		org.eclipse.wst.jsdt.core.infer.InferrenceProvider {

	IInferenceFile _inferenceFile;
	
	/**
	 * 
	 */
	public InferrenceProvider() {
		//
//		System.out.print("ctor\n");
	}

	/* (non-Javadoc)
	 * @see org.eclipse.wst.jsdt.core.infer.InferrenceProvider#getInferEngine()
	 */
	@Override
	public IInferEngine getInferEngine() {
		//
		InferEngine inferEngine = new InferEngine(this);
		inferEngine._inferenceFile = _inferenceFile;
		
		return inferEngine;
	}

	/* (non-Javadoc)
	 * @see org.eclipse.wst.jsdt.core.infer.InferrenceProvider#applysTo(org.eclipse.wst.jsdt.core.infer.IInferenceFile)
	 */
	@Override
	public int applysTo(IInferenceFile scriptFile) {
		
		String fname = new String(scriptFile.getFileName());
		
		//JavaScriptUnit jsu = scriptFile.
		
		if(fname.endsWith(".js"))
		{
			_inferenceFile = scriptFile;
			return MAYBE_THIS;
		}
		return MAYBE_THIS;
	}

	/* (non-Javadoc)
	 * @see org.eclipse.wst.jsdt.core.infer.InferrenceProvider#getID()
	 */
	@Override
	public String getID() {
		// 
		return "com.csf.qtassist";
	}

	/* (non-Javadoc)
	 * @see org.eclipse.wst.jsdt.core.infer.InferrenceProvider#getResolutionConfiguration()
	 */
	@Override
	public ResolutionConfiguration getResolutionConfiguration() {
		// 
		return new ResolutionConfiguration();
	}

	/* (non-Javadoc)
	 * @see org.eclipse.wst.jsdt.core.infer.InferrenceProvider#getRefactoringSupport()
	 */
	@Override
	public RefactoringSupport getRefactoringSupport() {
		// 
		return new RefactoringSupport();
	}

}
