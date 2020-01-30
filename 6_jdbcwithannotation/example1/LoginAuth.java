/**
 * 
 */
package dao_annotation;

import java.util.ResourceBundle;

/**
 * @author xikriz
 *
 */
public class LoginAuth {

	/**
	 * Check Authorization
	 * 
	 * @param username
	 * @param password
	 * @return boolean
	 */
	public static boolean checkAuth(String username, String password) {
		ResourceBundle sys = ResourceBundle.getBundle("sys");
		String sysUsername = sys.getString("username");
		String sysPassword = sys.getString("password");
		return sysUsername.equals(username) && sysPassword.equals(password);
	}
}
