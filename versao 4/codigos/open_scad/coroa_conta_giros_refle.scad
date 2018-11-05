
difference() {

 difference() {
  difference() {
   cylinder(2,31,31);
   for ( a = [0:90:340])   
    rotate([0,0,a]) 
    translate([0,19,0]){
     cylinder(3,1,1);
    }
  }
  cylinder(3,13,13);
 }
 
 for ( a = [0:22.5:340])   
 rotate([0,0,a]) 
 translate([0,23,0]){
  cube([3,8,3]);
 }

}