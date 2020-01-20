#ifndef TESTAREA_H
#define TESTAREA_H

#include <QObject>

class TestArea : public QObject
{
	Q_OBJECT

private slots:
	void triCellTest();
	void quadCellTest();
};

#endif // TESTAREA_H
