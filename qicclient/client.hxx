#ifndef QICCLIENT_CLIENT_HXX
#define QICCLIENT_CLIENT_HXX

#include <QObject>

namespace QICClient {

	using std::shared_ptr;
	class Catalog;
	class Product;
	class Ord;

	class Client : public QObject
	{
		Q_OBJECT

		public:
			/*!
			 * \brief Constructor.
			 * \param url Server root URL.
			 * \param certificate Path to the CA certificate file.
			 */
			Client(char const* url, char const* certificate = nullptr);
			~Client();

			/*!
			 * \brief For fetching products that belong a specific group.
			 * \param prodGroup The name of the product group.
			 * \param handler A pointer to a cURL write function callback.
			 */
			void results(QString const& prodGroup,
					size_t (*handler)(void*, size_t, size_t, void*));

			/*!
			 * \brief For fetching data about all active products.
			 * \param handler A pointer to a cURL write function callback.
			 */
			void allProducts(size_t (*handler)(void*, size_t, size_t, void*));

			/*!
			 * \brief For fetching data about a specific product.
			 * \param sku The SKU of the item to order.
			 * \param handler A pointer to a cURL write function callback.
			 */
			void flyPage(QString const& sku,
					size_t (*handler)(void*, size_t, size_t, void*));

			/*!
			 * \brief For putting an item to a cart.
			 * \param sku The SKU of the item to order.
			 * \param catalog The catalog from which the item is.
			 * \param order The order.
			 */
			void order(QString const& sku, Catalog const& catalog, Ord& order);

		public slots:
			/*
			void remove(unsigned int const& indices);
			void checkout();
			void newItem(QString const& description, QString const& comment,
					QString const& price, QString const& imagePath);
			*/

		signals:
			void gotResults(Catalog* catalog);
			void gotFlyPage(shared_ptr<Product> product);
	};

}

#endif // QICCLIENT_CLIENT_HXX
