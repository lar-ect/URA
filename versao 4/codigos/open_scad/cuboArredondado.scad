module cuboArredondado(xdim,ydim,zdim,rdim){
    hull(){
        translate([rdim,rdim])cylinder(r=rdim,h=zdim);
        translate([xdim-rdim,rdim,0])cylinder(r=rdim,h=zdim);
        translate([rdim,ydim-rdim])cylinder(r=rdim,h=zdim);
        translate([xdim-rdim,ydim-rdim,0])cylinder(r=rdim,h=zdim);
    }
}

cuboArredondado(50,50,10,12);