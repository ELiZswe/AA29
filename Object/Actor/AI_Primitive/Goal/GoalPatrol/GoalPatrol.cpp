// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/Goal/GoalPatrol/GoalPatrol.h"
#include "AA29/Object/Waypoint/Waypoint.h"

AGoalPatrol::AGoalPatrol()
{
	_score = 0.48;
}

/*
State Enabled
{
}
*/

void AGoalPatrol::Init()
{
	_constructWaypoints();
}

uint8 AGoalPatrol::getGoal()
{
	return 9;
}

void AGoalPatrol::EnemyNotVisible()
{
}

void AGoalPatrol::ReachedDestination()
{
	current_waypoint = current_waypoint->NextWaypoint;
	if (current_waypoint == nullptr)
	{
		_constructWaypoints();
	}
}

void AGoalPatrol::_constructWaypoints()
{
	UWaypoint* current_position = nullptr;
	UWaypoint* patrol_position = nullptr;
	/*
	current_position = new (None) UWaypoint::StaticClass();
	current_position.Location = getPawn().Location;
	patrol_position = new (None) UWaypoint::StaticClass();
	patrol_position.Location.X = current_position.Location.X + 500;
	patrol_position.Location.Y = current_position.Location.Y;
	patrol_position.Location.Z = current_position.Location.Z;
	current_waypoint = patrol_position;
	current_waypoint.NextWaypoint = current_position;
	*/
}
