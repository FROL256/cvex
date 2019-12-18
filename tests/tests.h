//// tests entry points
//
void run_all_tests();

//// vector-vector (+,-,*,/)
//
bool vf4_test001_basic();
bool vi4_test002_basic();
bool vu4_test003_basic();

//// vector-scalar (+,-,*,/)
//
bool vf4_test004_basic();
bool vi4_test005_basic();
bool vu4_test006_basic();

//// vector-vector (&,|,~)
//
bool vi4_test007_and_or();
bool vu4_test008_and_or();

//// vector-scalar (>>, <<)
//
bool vi4_test009_shift();
bool vu4_test010_shift();

//// splat
//
bool vf4_test011_splat();
bool vi4_test012_splat();
bool vu4_test013_splat();

//// convert
//
bool vfi4_test014_convert();
bool viu4_test015_convert();
