#include "vipl_add_random_noise.h"

template <class ImgIn,class ImgOut,class DataIn,class DataOut,class PixelItr>
bool vipl_add_random_noise <ImgIn,ImgOut,DataIn,DataOut,PixelItr> :: section_applyop(){
  DataIn dummy = DataIn(); // dummy initialization to avoid compiler warning
  for(int j = start(Y_Axis()); j < stop(Y_Axis()); ++j)
    for(int i = start(X_Axis(),j); i < stop(X_Axis(),j); ++i) {
#ifdef STAT_LIB
      DataOut p = fgetpixel(in_data(),i,j,dummy) + (DataOut)(distrib_->Draw(&seed_));
#else
      seed_ *= 1366; seed_ += 150889; seed_ %= 714025;
      DataOut p = fgetpixel(in_data(),i,j,dummy) + (DataOut)(maxdev_*(seed_-357012)/357012);
#endif
      setpixel(out_data(), i, j, p);
  }
  return true;
}
