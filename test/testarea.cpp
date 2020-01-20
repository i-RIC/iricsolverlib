#include "testarea.h"

#include <iricsolverlib_cell2d.h>
#include <iricsolverlib_grid2d.h>
#include <iricsolverlib_quadcell.h>
#include <iricsolverlib_rect2d.h>
#include <iricsolverlib_tricell.h>

#include <QtTest>

using namespace iRICSolverLib;

void TestArea::triCellTest()
{
	Grid2D grid;
	grid.addNode(0, 0);
	grid.addNode(1, 0);
	grid.addNode(0, 2);

	grid.addTriCell(1, 2, 3);

	Cell2D* cell = grid.cell(1);

	QVERIFY(cell->area() == 1);
}

void TestArea::quadCellTest()
{
	Grid2D grid;
	grid.addNode(0, 0);
	grid.addNode(1, 0);
	grid.addNode(0, 2);
	grid.addNode(1, 2);

	grid.addQuadCell(1, 2, 4, 3);

	Cell2D* cell = grid.cell(1);

	// area is nearly equal 2.0
	double area = cell->area();
	QVERIFY(area > 1.999);
	QVERIFY(area < 2.001);
}
