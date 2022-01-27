#include "colors.inc"
#include "textures.inc"
#include "metals.inc"
#include "finish.inc"
#include "unixtextures.inc"
#include "room.inc"
#include "lamp.inc"
#include "table.inc"
#include "chair.inc"
#include "computer.inc"
#include "setup.inc"
#include "wall.inc"

camera {
	 location <0, 250, -400>
   angle 60
   right x*image_width/image_height // keep propotions with any aspect ratio
	 look_at <-15, 0, 0>
}

#declare scene = union {
  object { room }
	object { lamps }
	object { setup }
	object { wall }
}

object { scene
	translate -(w/2)*x
	translate -(l/2)*z
	rotate y*-45 
}