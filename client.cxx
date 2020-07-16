#include <cstddef>
#include <memory>
#include <QObject>
#include <icclient/client.h>
#include <icclient/member.h>
#include "qicclient/catalog.hxx"
#include "qicclient/ord.hxx"
#include "qicclient/client.hxx"

namespace QICClient {

	Client::Client(char const* url, char const* certificate)
	{
		icclient_init(url, certificate);
	}

	Client::~Client()
	{
		icclient_cleanup();
	}

	void Client::results(QString const& prodGroup,
			size_t (*handler)(void*, size_t, size_t, void*))
	{
		icclient_catalog* catalog = nullptr;
		icclient_results(prodGroup.toLatin1().constData(), handler, &catalog);
		if (catalog) emit gotResults(new Catalog{catalog});
	}

	void Client::allProducts(size_t (*handler)(void*, size_t, size_t, void*))
	{
		icclient_catalog* catalog = nullptr;
		icclient_allproducts(handler, &catalog);
		if (catalog) emit gotResults(new Catalog{catalog});
	}

	void Client::flyPage(QString const& sku,
			size_t (*handler)(void*, size_t, size_t, void*))
	{
		icclient_product* product = nullptr;
		icclient_flypage(sku.toLatin1().constData(), handler, &product);
		if (product) emit gotFlyPage(shared_ptr<Product>{new Product{product}});
	}

	void Client::order(QString const& sku, Catalog const& catalog, Ord& order)
	{
		auto c_order = order.data();
		icclient_ord_order(sku.toLatin1().constData(), catalog.constData(),
				&c_order);
		order.setData(c_order);
	}

}
