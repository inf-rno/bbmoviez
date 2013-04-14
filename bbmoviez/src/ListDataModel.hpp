#ifndef ListDataModel_HPP_
#define ListDataModel_HPP_

#include <bb/cascades/GroupDataModel>

class ListDataModel : public bb::cascades::GroupDataModel
{
    Q_OBJECT

public:
    explicit ListDataModel(QObject* parent = 0);

private Q_SLOTS:

private:
	QVariantList m_myMovies;
};

#endif /* ListDataModel_HPP_ */
