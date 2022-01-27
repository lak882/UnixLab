/* DEPTH OF FLOOR / WALLS */
#declare d = -10;
/* TOTAL WIDTH AND LENGTH OF ROOM */
#declare w = 378;
#declare l = 280;
/* HEIGHT */
#declare h = 105;
/* HEIGHT OF INDENT */
#declare hi = 95;

/* FLOOR OF ROOM */
#declare Floor = difference {
	box {
		<0, d, 0>
		<w, 0, l>
	}
	#declare cutout = box {
		<-0.001, d*1.001, -0.001>
		<1.001, 0.001, 1.001>
	}
	// big front cutout
	object{ cutout
		scale x*218
		scale z*32
		translate x*80
	} 
	// front cutouts
	object { cutout
		scale x*35
		scale z*78
	}
	object { cutout
		scale x*35
		scale z*78
		translate x*343
	}
	// back cutouts
	object { cutout 
		scale x*35
		scale z*10
		translate z*270
	}
	object { cutout 
		scale x*35
		scale z*10
		translate z*270
		translate x*343
	}	
}

/* wall w/ thickness 10 in z-axis */
#declare XWall = box {
	// y starts at depth to match floor
	// z starts at depth to add thickness
	<0, d, 0>
	<1,  h, 10>
}

/* wall w/ thickness 10 in x-axis */
#declare ZWall = box {
	<0,  d, 0>
	<10,  h, 1>
}

#declare Walls = union {
	object { XWall
		scale x*35
		translate z*270
	}
	object { ZWall 
		scale z*10
		translate <25, 0, 270>
	}
	object { XWall
		scale x*45
		translate <343, 0, 270> 
	}
	object { ZWall 
		scale z*10
		translate <343, 0, 270>
	}
	object { XWall
		scale x*338
		translate <25, 0, 280>
	}
	object { XWall
		scale x*35
		translate z*270
	}
	// window wall
	difference {
		object { ZWall
			scale z*192
			translate <378, 0, 78>
		}
		// idnent cutouts
		box { 
			<-0.001, 12, 0>
			<1.0001, h*1.001, 91>
			translate <378, 0, 78>
		}
		box {
			<-0.001, 12, 0>
			<1.0001, h*1.001, 91>
			translate <378, 0, 179>
		}
		// window cut outs
		box { 
			<-0.001, 16, 0>
			<10.001, h-2, 83>
			translate <378, 0, 82>
		}
		box {
			<-0.001, 16, 0>
			<10.0001, h-2, 83>
			translate <378, 0, 183>
		}
	}
	// windows
	box {
		<0, 16, 0>
		<1, h-2, 83>
		translate <378+4.5, 0, 82>
		texture { window }
	}
	box {
		<0, 16, 0>
		<1, h-2, 83>
		translate <378+4.5, 0, 183>
		texture { window }
	}
	// photo behind window
	box {
		<0, 16, 0>
		<83, h-2, 1>
		texture { pigment { image_map {
		png "text/window1" once} scale<83, 87, 0> 
		translate y*16} }
		rotate y*90
		translate <378+9, 0, 82+83> 
	}
	box {
		<0, 16, 0>
		<83, h-2, 1>
		texture { pigment { image_map {
		png "text/window2" once} scale<83, 87, 0>
		translate y*16 } }
		rotate y*90
		translate <378+9, 0, 183+83> 
	}
	object { XWall
		scale x*35
		translate <343, 0, 78>
	}
	object { ZWall
		scale z*78
		translate x*343
	}
	difference { 
		object { XWall
			scale x*55
			translate x*298
			translate z*-10
		}
		box {
			<-0.001, d*1.001, -0.001>
			<34, 83, 10.001>
			translate x*306
			translate z*-10
		}
	}
}

#declare Celling = union {
	difference{
		#declare cutout = box {
			<-0.001, -0.001, -0.001>
			<1.001, 10.001, 1.001>
		}
		box {
			<0,   0,  0>
			<55, 10, 280>
		}
		object{ cutout
			scale <35, 1, 78>
			translate x*20
		}
		object{ cutout
			scale <35, 1, 10>
			translate x*20
			translate z*270
		}
		translate y*hi
		translate x*323
	}	
	box {
		<0, 0, 0>
		<25, 10, 32>
		translate y*hi
		translate x*298
	}
}
	
#declare Carpet = intersection {
	object { Floor }
	plane { 
		y, 0
		pigment {
			image_map { png "text/floor_texture.png" }
		}
	}
}

#declare room = union {
  object { Floor }
  object { Carpet }
	object { Walls }
	texture { wallPart }
}