#include <icclient/admin.h>
#include "qicclient/admin.hxx"

namespace QICClient {

	void Admin::logIn(QString const& username, QString const& password)
	{
		icclient_admin_login(username.toLatin1().constData(), password.toLatin1().constData(), nullptr, nullptr);
	}

	void Admin::setUserName(QString const& userName)
	{
		if (m_userName != userName) {
			m_userName = userName;
			emit userNameChanged();
		}
	}
	void Admin::setPassword(QString const& password)
	{
		if (m_password != password) {
			m_password = password;
			emit passwordChanged();
		}
	}
	void Admin::setName(QString const& name)
	{
		if (m_name != name) {
			m_name = name;
			emit nameChanged();
		}
	}
	void Admin::setSuper(bool super)
	{
		if (m_super != super) {
			m_super = super;
			emit superChanged();
		}
	}

	void Admin::setData(icclient_admin* data)
	{
		if (data && data->username && m_userName != data->username) {
			m_userName = QString{data->username};
			emit userNameChanged();
		} else setUserName("");

		if (data && data->password && m_password != data->password) {
			m_password = QString{data->password};
			emit passwordChanged();
		} else setPassword("");

		if (data && data->name && m_name != data->name) {
			m_name = QString{data->name};
			emit nameChanged();
		} else setName("");

		if (data) setSuper(data->super);
		else setSuper("");

		if (m_data != data) m_data = data;
	}

	void Admin::newAdmin(QString const& userName, QString const& password, QString const& name, bool super,
			enum icclient_admin_group group)
	{
		icclient_admin_new_admin(userName.toLatin1().constData(), password.toLatin1().constData(),
				name.toLatin1().constData(), super, group, nullptr);
	}

	void Admin::newItem(QString const& description, QString const& comment,
			QString const& price, QString const& imagePath)
	{
		icclient_admin_new_item(description.toLatin1().constData(), comment.toLatin1().constData(),
				price.toLatin1().constData(), imagePath.toLatin1().constData(), nullptr);
	}

	void Admin::logOut()
	{
		icclient_admin_logout(m_data, nullptr);
		setData(nullptr);
	}

}
