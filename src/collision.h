/*
Minetest-c55
Copyright (C) 2010 celeron55, Perttu Ahola <celeron55@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef COLLISION_HEADER
#define COLLISION_HEADER

#include "common_irrlicht.h"
#include <vector>

class Map;
class IGameDef;

struct collisionMoveResult
{
	bool touching_ground;
	bool collides;
	bool collides_xz;
	bool standing_on_unloaded;	

	collisionMoveResult():
		touching_ground(false),
		collides(false),
		collides_xz(false),
		standing_on_unloaded(false)		
	{}
};

// Moves using a single iteration; speed should not exceed pos_max_d/dtime
collisionMoveResult collisionMoveSimple(Map *map, IGameDef *gamedef,
		f32 pos_max_d, const aabb3f &box_0,
		f32 stepheight, f32 dtime,
		v3f &pos_f, v3f &speed_f, v3f &accel_f);	

// Moves using as many iterations as needed
collisionMoveResult collisionMovePrecise(Map *map, IGameDef *gamedef,
		f32 pos_max_d, const aabb3f &box_0,
		f32 stepheight, f32 dtime,
		v3f &pos_f, v3f &speed_f, v3f &accel_f);

// Helper function:
// Checks for collision of a moving aabbox with a static aabbox
// Returns -1 if no collision, 0 if X collision, 1 if Y collision, 2 if Z collision
// dtime receives time until first collision, invalid if -1 is returned
int axisAlignedCollision(
		const aabb3f &staticbox, const aabb3f &movingbox,
		const v3f &speed, f32 d, f32 &dtime);

// Helper function:
// Checks if moving the movingbox up by the given distance would hit a ceiling.
bool wouldCollideWithCeiling(
		const std::vector<aabb3f> &staticboxes,
		const aabb3f &movingbox,
		f32 y_increase, f32 d);

// Moves using a single iteration; speed should not exceed pos_max_d/dtime
collisionMoveResult collisionMoveSimpleOld(Map *map, IGameDef *gamedef,
		f32 pos_max_d, const core::aabbox3d<f32> &box_0,
		f32 dtime, v3f &pos_f, v3f &speed_f);

// Moves using as many iterations as needed
collisionMoveResult collisionMovePreciseOld(Map *map, IGameDef *gamedef,
		f32 pos_max_d, const core::aabbox3d<f32> &box_0,
		f32 dtime, v3f &pos_f, v3f &speed_f);


enum CollisionType
{
	COLLISION_FALL
};

struct CollisionInfo
{
	CollisionType t;
	f32 speed;
};

#endif

