#ifndef VEHICLE_H__
#define VEHICLE_H__

#include <btBulletDynamicsCommon.h>
#include <BulletCollision/CollisionShapes/btHeightfieldTerrainShape.h>

#include <BulletDynamics/MLCPSolvers/btDantzigSolver.h>
#include <BulletDynamics/MLCPSolvers/btSolveProjectedGaussSeidel.h>
#include <BulletDynamics/MLCPSolvers/btMLCPSolver.h>

class btVehicleTuning;

class btCollisionShape;

#include <BulletDynamics/ConstraintSolver/btHingeConstraint.h>
#include <BulletDynamics/ConstraintSolver/btSliderConstraint.h>

#include <../examples/CommonInterfaces/CommonExampleInterface.h>
#include <LinearMath/btAlignedObjectArray.h>
#include <btBulletCollisionCommon.h>
#include <../examples/CommonInterfaces/CommonGUIHelperInterface.h>
#include <../examples/CommonInterfaces/CommonRenderInterface.h>
#include <../examples/CommonInterfaces/CommonWindowInterface.h>
#include <../examples/CommonInterfaces/CommonGraphicsAppInterface.h>

#include <../examples/CommonInterfaces/CommonRigidBodyBase.h>

class CommonExampleInterface* VehicleCreateFunc(struct CommonExampleOptions& options);

#endif  // VEHICLE_H__
