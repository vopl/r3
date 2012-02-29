package com.csf.qtassist;

import java.util.logging.Level;
import java.util.logging.Logger;
import org.eclipse.core.runtime.ILogListener;
import org.eclipse.core.runtime.IStatus;
import org.eclipse.core.runtime.Plugin;
import org.eclipse.core.runtime.Status;
import org.osgi.framework.BundleActivator;
import org.osgi.framework.BundleContext;

public class Activator extends Plugin implements BundleActivator {

	public static final String PLUGIN_ID = "com.csf.qtassist";
	private static Activator _plugin;
	private ILogListener _logListener;


	/*
	 * (non-Javadoc)
	 * 
	 * @see
	 * org.osgi.framework.BundleActivator#start(org.osgi.framework.BundleContext
	 * )
	 */
	public void start(BundleContext bundleContext) throws Exception {
		super.start(bundleContext);
	    _plugin = this;

		_logListener = new ILogListener() {

			private Logger logger = Logger.getLogger(PLUGIN_ID);

			@Override
			public void logging(IStatus status, String pluginName) {
				if (status == null) {
					return;
				}

				int severity = status.getSeverity();
				Level level = Level.ALL;
				if (severity == Status.ERROR) {
					level = Level.WARNING;
				} else if (severity == Status.WARNING) {
					level = Level.WARNING;
				} else if (severity == Status.INFO) {
					level = Level.INFO;
				} else if (severity == Status.CANCEL) {
					level = Level.WARNING;
				}

				pluginName = formatText(pluginName);
				String statusPlugin = formatText(status.getPlugin());
				String statusMessage = formatText(status.getMessage());
				StringBuffer message = new StringBuffer();
				if (pluginName != null) {
					message.append(pluginName);
					message.append(" - ");
				}
				if (statusPlugin != null
						&& (pluginName == null || !statusPlugin
								.equals(pluginName))) {

					message.append(statusPlugin);
					message.append(" - ");
				}
				message.append(status.getCode());
				if (statusMessage != null) {
					message.append(" - ");
					message.append(statusMessage);
				}

				logger.log(level, message.toString(), status.getException());
			}

			private String formatText(String text) {
				if (text != null) {
					text = text.trim();
					if (text.length() == 0) {
						return null;
					}
				}

				return text;
			}

		};

		_plugin.getLog().addLogListener(_logListener);
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see
	 * org.osgi.framework.BundleActivator#stop(org.osgi.framework.BundleContext)
	 */
	public void stop(BundleContext bundleContext) throws Exception {
		_plugin.getLog().removeLogListener(_logListener);
		_plugin = null;
		super.stop(bundleContext);
	}

	public static void log(String string) {


		IStatus status = new Status(IStatus.ERROR, "com.csf.qtassist", string);
		_plugin.getLog().log(status);

	}

}
