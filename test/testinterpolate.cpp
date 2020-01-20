#include "testinterpolate.h"

#include <iricsolverlib_grid2d.h>
#include <iricsolverlib_point2d.h>
#include <iricsolverlib_quadcell.h>
#include <iricsolverlib_rect2d.h>
#include <iricsolverlib_tricell.h>

#include <QtTest>

using namespace iRICSolverLib;

void TestInterpolate::initTestCase()
{
	m_grid.addNode(2, 1);
	m_grid.addNode(5, 1);
	m_grid.addNode(8, 1);
	m_grid.addNode(10, 1);
	m_grid.addNode(2, 4);
	m_grid.addNode(5, 3);
	m_grid.addNode(8, 3);
	m_grid.addNode(11, 3);
	m_grid.addNode(5, 6);
	m_grid.addNode(8, 5);
	m_grid.addNode(10, 5);

	m_grid.addTriCell(1, 2, 6);
	m_grid.addQuadCell(2, 3, 7, 6);
	m_grid.addTriCell(3, 4, 7);
	m_grid.addTriCell(4, 8, 7);
	m_grid.addTriCell(1, 6, 5);
	m_grid.addTriCell(5, 6, 9);
	m_grid.addTriCell(6, 10, 9);
	m_grid.addQuadCell(6, 7, 11, 10);
	m_grid.addTriCell(7, 8, 11);

	m_grid.setupBackGrid();
}

void TestInterpolate::cleanupTestCase()
{}

void TestInterpolate::interpolateTriCell()
{
	int count;
	size_t ids[4];
	double weights[4];
	bool ok;

	ok = m_grid.interpolate(Point2D(4, 2), &count, &(ids[0]), &(weights[0]));
	QVERIFY(ok == true);

	ok = m_grid.interpolate(Point2D(1, 5), &count, &(ids[0]), &(weights[0]));
	QVERIFY(ok == false);

	ok = m_grid.interpolate(Point2D(15, 4), &count, &(ids[0]), &(weights[0]));
	QVERIFY(ok == false);

	ok = m_grid.interpolate(Point2D(8, 0), &count, &(ids[0]), &(weights[0]));
	QVERIFY(ok == false);

	ok = m_grid.interpolate(Point2D(2, 1), &count, &(ids[0]), &(weights[0]));
	QVERIFY(ok == true);
	QVERIFY(weights[0] == 1);
}

void TestInterpolate::interpolateQuadCell()
{
	int count;
	size_t ids[4];
	double weights[4];
	bool ok;

	ok = m_grid.interpolate(Point2D(5, 1), &count, &(ids[0]), &(weights[0]));
	QVERIFY(ok == true);

	ok = m_grid.interpolate(Point2D(8, 3), &count, &(ids[0]), &(weights[0]));
	QVERIFY(ok == true);
	QVERIFY(weights[2] == 1);

	ok = m_grid.interpolate(Point2D(6, 2), &count, &(ids[0]), &(weights[0]));
	QVERIFY(ok == true);
}
