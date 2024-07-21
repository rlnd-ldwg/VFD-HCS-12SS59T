/*
 * spacer for VFD  Samsung HCS-12SS59T
 */

// global parameters
$fn = 1000;
co = 0.01;
_2co = 2 * co;
debug = false;

spacer = [10.0, 100.0, 3.2];
hole_dist = 92.5;
hole_dia = 3.2;
countersunk_depth = 2.0; 
countersunk_dia = 5.75;

dist2edge = [3.4, (spacer.y - hole_dist) / 2];



difference(){
    cube(spacer);
    translate([dist2edge.x, dist2edge.y, -co])
    cylinder(h = spacer.z + _2co, d = hole_dia);
    translate([dist2edge.x, dist2edge.y, spacer.z - countersunk_depth])
    cylinder(h = countersunk_depth + _2co, d = countersunk_dia);
    translate([dist2edge.x, spacer.y - dist2edge.y, -co])
    cylinder(h = spacer.z + _2co, d = hole_dia);
    translate([dist2edge.x, spacer.y - dist2edge.y, spacer.z - countersunk_depth])
    cylinder(h = countersunk_depth + _2co, d = countersunk_dia);
}