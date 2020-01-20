#include "testarea.h"
#include "testinterpolate.h"
#include "testregion.h"

#include <QCoreApplication>
#include <QtTest>

int main(int argc, char* argv[])
{
	QCoreApplication app(argc, argv);
	app.setAttribute(Qt::AA_Use96Dpi, true);

	int ret = 0;

	TestInterpolate ti;
	ret = ret + QTest::qExec(&ti, argc, argv);

	TestRegion tr;
	ret = ret + QTest::qExec(&tr, argc, argv);

	TestArea ta;
	ret = ret + QTest::qExec(&ta, argc, argv);

	return ret;
}
