#declare keyboard = union {
	// keyboard itself
	box { <0, 0, 0> <18, 0.75, 6.5> }
	#declare button = box {
		<0, 0, 0> <1, 0.25, 0.75>
		translate y*0.75
	}
	// top row of buttons
	object{ button translate <1, 0, 5> } 
	object{ button scale x*3 translate <2.5, 0, 5> }
	object{ button scale x*3 translate <5.75, 0, 5> }
	object{ button scale x*2.5 translate <9, 0, 5> }
	
	// middle row at 12
	object{ button scale x*2.5 translate <12, 0, 5> }
	object{ button scale x*2.5 scale z*2 translate <12, 0, 3.25> }
	object{ button translate <12.83, 0, 1.5> }
	object{ button scale x*2.5 translate <12, 0, 0.75> }
	
	#declare pad = box {
		<0, 0, 0> <1, 0.25, 4>
		translate y*0.75
	}
	//letter pad
	object{ pad scale x*11 translate <0.25, 0, 0.75> }
	// num pad
	object{ pad scale x*3 translate <14.75, 0, 0.75> }
}

#declare monitor = union {
	cylinder { <0, 0, 0> <0, 0.5, 0> 4
	 translate x*11.25 }	 
	difference {
	 cylinder { <0, 0, 0> <0, 5, 0> 1 
	 rotate x*-30
	 translate x*11.25
	 translate z*1.0}
	 box { <0, 0, -10> <22.5, 13, 1.5> 
	 		translate y*2.5
			rotate x*10
			translate z*-2}
	}
	difference {
		box { <0, 0, 0> <22.5, 13, 1.5> }
		box { <1, 1, -1> <20.5, 12, 0.25> }
			translate y*2.5
			rotate x*10
			translate z*-2
	}
	
}

#declare computer = union {
	// (x of monitor - x of keyboard) / 2
	object{ keyboard translate x*2.25
	texture { greyPart } }
	object{ monitor translate z*15 
	texture { pigment {color Black} finish {reflective} }}
}