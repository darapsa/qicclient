#ifndef QICCLIENT_CATALOG_HXX
#define QICCLIENT_CATALOG_HXX

#include <QAbstractListModel>
#include "product.hxx"

struct icclient_catalog;

namespace ICClient {

	class Catalog : public QAbstractListModel
	{
		Q_OBJECT

		public:
			Catalog(icclient_catalog* catalog, QObject* parent = nullptr);
			Catalog(QObject* parent = nullptr) : QAbstractListModel{parent} {}
			int rowCount(QModelIndex const& parent = QModelIndex()) const Q_DECL_OVERRIDE;
			QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
			icclient_catalog const* c_catalog() const { return catalog; }

		public slots:
			void update(Catalog* catalog);

		signals:
			void updated();

		protected:
			QHash<int, QByteArray> roleNames() const Q_DECL_OVERRIDE;

		private:
			void addProduct(Product const& product);
			QList<Product> products;
			icclient_catalog* catalog;
	};

}

#endif // QICCLIENT_CATALOG_HXX
