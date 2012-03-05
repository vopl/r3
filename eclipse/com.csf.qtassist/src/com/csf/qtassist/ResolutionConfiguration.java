package com.csf.qtassist;

public class ResolutionConfiguration extends
		org.eclipse.wst.jsdt.core.infer.ResolutionConfiguration {

	public String [] getContextIncludes()
	{
		return null;
	}
	
	/**
	 * Determine if all files in include path should be searched to resolve a name.
	 * If false, names will be resolved using only libraries, imports, and context includes 
	 * 
	 * @return true 
	 */
	public boolean searchAllFiles()
	{
		return true;
	}
	
}
