#ifndef TESTREGION_H
#define TESTREGION_H

#include <QObject>

class TestRegion : public QObject
{
	Q_OBJECT

private slots:
	void triCellTest();
	void quadCellTest();
};

#endif // TESTREGION_H

