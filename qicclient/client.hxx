#ifndef QICCLIENT_CLIENT_HXX
#define QICCLIENT_CLIENT_HXX

#include <QObject>

struct icclient_catalog;
struct icclient_ord_order;

namespace ICClient {

	class Client : public QObject
	{
		Q_OBJECT

		public:
			Client(char const* url, char const* certificate = nullptr);
			~Client();

			void allProducts(size_t (*handler)(void* contents
						, size_t size, size_t nmemb
						, void* userdata));
			void order(icclient_ord_order** orderPtr, QString const& sku
					, icclient_catalog* catalog);

		public slots:
			/*
			void remove(unsigned int const& indices);
			void checkout();
			*/
			void logIn(QString const& username
					, QString const& password);
		/*
			void account(QString const& firstName
					, QString const& lastName
					, QString const& address1
					, QString const& address2
					, QString const& city
					, QString const& state
					, QString const& zip
					, QString const& email
					, QString const& phoneDay);
			void changePassword(QString const& passwordOld
					, QString const& password
					, QString const& verify);
					*/
			void logOut();
			/*
			void newItem(QString const& description
					, QString const& comment,
					QString const& price
					, QString const& imagePath);
					*/

		signals:
			void gotAllProducts(icclient_catalog* catalog);
			void ordered(icclient_ord_order* order);
			void loggedIn(QString const& userName);
			void loggedOut();
	};

}

#endif // QICCLIENT_CLIENT_HXX
