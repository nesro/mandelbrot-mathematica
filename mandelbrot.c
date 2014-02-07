/**
 * https://github.com/nesro/mandelbrot-mathematica
 * Tomas Nesrovnal
 * nesro@nesro.cz
 */

#include "WolframLibrary.h"

/**
 * http://en.wikipedia.org/wiki/Mandelbrot_set
 * @param _Real x
 * @param _Real y
 * @param _Integer maximum iterations
 * @return _Integer iterations until escape, 0 if it never escapes
 */
DLLEXPORT int mandelbrot(WolframLibraryData libData, mint Argc,
    MArgument *Args, MArgument Res)
{
	mreal re = MArgument_getReal(Args[0]);
	mreal im = MArgument_getReal(Args[1]);		
	mint  max_iters = MArgument_getInteger(Args[2]);
	
	mreal Z_im = 0.;
	mreal Z_re = 0.;
	mreal Z_im2 = 0.;
	mreal Z_re2 = 0.;
	
    mint iter = 0;
    for (; (iter < max_iters) && (Z_re2 + Z_im2 < 4); iter++) {
        Z_im = 2. * Z_im * Z_re + im;
        Z_re = Z_re2 - Z_im2 + re;
        
        Z_im2 = Z_im * Z_im;
        Z_re2 = Z_re * Z_re;
    }

    if (iter == max_iters) 
        iter = 0;

    MArgument_setInteger(Res, iter);
    return LIBRARY_NO_ERROR;
}

