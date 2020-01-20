#include "testregion.h"

#include <iricsolverlib_grid2d.h>
#include <iricsolverlib_quadcell.h>
#include <iricsolverlib_rect2d.h>
#include <iricsolverlib_tricell.h>

#include <QtTest>

using namespace iRICSolverLib;

void TestRegion::triCellTest()
{
	Grid2D grid;
	grid.addNode(0, 0);
	grid.addNode(1, 0);
	grid.addNode(0, 2);
	grid.addNode(0.2, 1);

	grid.addTriCell(1, 2, 4);
	grid.addTriCell(1, 4, 3);

	Rect2D rect = grid.boundingRect();
	QVERIFY(rect.xMin() == 0);
	QVERIFY(rect.xMax() == 1);
	QVERIFY(rect.yMin() == 0);
	QVERIFY(rect.yMax() == 2);
}

void TestRegion::quadCellTest()
{
	Grid2D grid;
	grid.addNode(0, 0);
	grid.addNode(1, 0);
	grid.addNode(0, 2);
	grid.addNode(0.8, 1.8);

	grid.addQuadCell(1, 4, 3, 2);

	Rect2D rect = grid.boundingRect();
	QVERIFY(rect.xMin() == 0);
	QVERIFY(rect.xMax() == 1);
	QVERIFY(rect.yMin() == 0);
	QVERIFY(rect.yMax() == 2);
}
