/**
 * @brief 
 * 
 * @file utilib.h
 * @author your name
 * @date 2018-04-07
 */

#ifndef phoenixutil_h
#define phoenixutil_h

/**
 * @brief Convert from degrees to radians
 * 
 * @param deg value in degrees 
 * @return double value in radians
 */
double toRad(double deg);
/**
 * @brief Convert from radians to degrees
 * 
 * @param rad value in radians
 * @return double value in degrees
 */
double toDeg(double rad);
/**
 * @brief Keep the value f rotating between min and max.
 * 
 * @param f value to constraint
 * @param min minimum wanted value.
 * @param max maximum wanted value.
 * @return double 
 */
double circConstraint(double f, double min, double max);

#endif