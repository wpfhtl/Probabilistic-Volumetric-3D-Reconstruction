//:
// \file
// \brief Example of generating functions to manipulate views.
// \author Tim Cootes - Manchester

#include <vil2/vil2_image_view.h>
#include <vil/vil_byte.h>
#include <vcl_iostream.h>

//: Example function to return a transpose of the view
vil2_image_view<vil_byte> vil2_transpose(const vil2_image_view<vil_byte>& v)
{
  // Create view with x and y switched
  return vil2_image_view<vil_byte>(v.memory_chunk(),v.top_left_ptr(),
                                   v.ny(),v.nx(),v.nplanes(),
                                   v.ystep(),v.xstep(),v.planestep());
}

int main(int argc, char** argv)
{
  int nx=8;
  int ny=8;
  vil2_image_view<vil_byte> image(nx,ny);

  // Slow fill
  for (int y=0;y<ny;++y)
    for (int x=0;x<nx;++x)
      image(x,y) = vil_byte(x+10*y);

  vcl_cout<<"Original image:"<<vcl_endl;
  image.print_all(vcl_cout);

  vcl_cout<<vcl_endl;
  vcl_cout<<"Create transposed view of plane"<<vcl_endl;
  vil2_image_view<vil_byte> transpose = vil2_transpose(image);
  transpose.print_all(vcl_cout);

  return 0;
}
