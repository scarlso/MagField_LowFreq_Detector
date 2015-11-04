#include "Filter.h"
#include "Filter_PVT.h"


/*******************************************************************************
* ChannelA filter coefficients.
* Filter Type is FIR
*******************************************************************************/

/* Renamed array for backward compatibility.
*  Should not be used in new designs.
*/
#define ChannelAFirCoefficients Filter_ChannelAFirCoefficients

/* Number of FIR filter taps are: 15 */

const uint8 CYCODE Filter_ChannelAFirCoefficients[Filter_FIR_A_SIZE] = 
{
 0xE9u, 0xF5u, 0xFFu, 0x00u, /* Tap(0), -0.000307917594909668 */

 0xFEu, 0x75u, 0x00u, 0x00u, /* Tap(1), 0.0036008358001709 */

 0x94u, 0xBFu, 0xFEu, 0x00u, /* Tap(2), -0.00977849960327148 */

 0xABu, 0x3Du, 0x00u, 0x00u, /* Tap(3), 0.00188195705413818 */

 0x1Fu, 0x1Eu, 0x06u, 0x00u, /* Tap(4), 0.0477942228317261 */

 0xF3u, 0x40u, 0xF0u, 0x00u, /* Tap(5), -0.123017907142639 */

 0x12u, 0x1Au, 0x0Au, 0x00u, /* Tap(6), 0.0789206027984619 */

 0xCCu, 0x92u, 0x3Du, 0x00u, /* Tap(7), 0.481042385101318 */

 0x12u, 0x1Au, 0x0Au, 0x00u, /* Tap(8), 0.0789206027984619 */

 0xF3u, 0x40u, 0xF0u, 0x00u, /* Tap(9), -0.123017907142639 */

 0x1Fu, 0x1Eu, 0x06u, 0x00u, /* Tap(10), 0.0477942228317261 */

 0xABu, 0x3Du, 0x00u, 0x00u, /* Tap(11), 0.00188195705413818 */

 0x94u, 0xBFu, 0xFEu, 0x00u, /* Tap(12), -0.00977849960327148 */

 0xFEu, 0x75u, 0x00u, 0x00u, /* Tap(13), 0.0036008358001709 */

 0xE9u, 0xF5u, 0xFFu, 0x00u, /* Tap(14), -0.000307917594909668 */
};

