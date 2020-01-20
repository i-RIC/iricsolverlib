#ifndef TESTINTERPOLATE_H
#define TESTINTERPOLATE_H

#include "iricsolverlib_grid2d.h"

#include <QObject>

class TestInterpolate : public QObject
{
	Q_OBJECT

private slots:
	void initTestCase();
	void cleanupTestCase();

	void interpolateTriCell();
	void interpolateQuadCell();

private:
	iRICSolverLib::Grid2D m_grid;
};

#endif // TESTINTERPOLATE_H
