/*****************************************************************************
 *                                                                           *
 *          UNURAN -- Universal Non-Uniform Random number generator          *
 *                                                                           *
 *****************************************************************************
 *                                                                           *
 *   FILE: norta.h                                                           *
 *                                                                           *
 *   PURPOSE:                                                                *
 *         function prototypes for method NORTA                              *
 *         (NORmal To Anything)                                              *
 *                                                                           *
 *   USAGE:                                                                  *
 *         only included in unuran.h                                         *
 *                                                                           *
 *****************************************************************************
 *                                                                           *

 *                                                                           *

 *                                                                           *
 *****************************************************************************/

/* 
   =METHOD  NORTA  NORmal To Anything

   =UP  Methods_for_CVEC

   =REQUIRED  rank correlation matrix, marginal distributions

   =SPEED Set-up: slow,
          Sampling: depends on dimension

   =REINIT not implemented

   =REF  [HLD04: Sect.12.5.2, Alg.12.11.]

   =DESCRIPTION
      NORTA (NORmal to anything) is a model to get random vectors with
      given marginal distributions and rank correlation. 

      @strong{Important:} Notice that marginal distribution and (rank)
      correlation structure do not uniquely define a multivariate
      distribution. Thus there are many other (more or less sensible)
      models.

      In the NORTA model multinormal random variates with the given
      (Spearman's) rank correlations are generated. 
      In a second step the (standard normal distributed) marginal variates
      are transformed by means of the CDF of the normal distribution to get
      uniform marginals. The resulting random vectors have uniform
      marginals and the desired rank correlation between its components.
      Such a random vector is called 'copula'.

      By means of the inverse CDF the uniform marginals are then
      transformed into the target marginal distributions. This
      transformation does not change the rank correlation.
      
      For the generation of the multinormal distribution the
      (Spearman's) rank correlation matrix is transformed into the
      corresponding (Pearson) correlation matrix. Samples from the
      resulting multinormal distribution are generated by means of the
      Cholesky decomposition of the covariance matrix.

      It can happen that the desired rank correlation matrix is not
      feasible, i.e., it cannot occur as rank correlation matrix of a
      multinormal distribution. The resulting "covariance" matrix is
      not positive definite. In this case an eigenvector correction
      method is used. Then all non-positive eigenvalues are set to a
      small positive value and hence the rank correlation matrix of the
      generated random vectors is "close" to the desired matrix.
      
   =HOWTOUSE
      Create a multivariate generator object and set marginal 
      distributions using unur_distr_cvec_set_marginals(), 
      unur_distr_cvec_set_marginal_array(), or 
      unur_distr_cvec_set_marginal_list().
      (Do not use the corresponding calls for the standard
      marginal distributions).

      When the domain of the multivariate distribution is set by of a
      unur_distr_cvec_set_domain_rect() call then the domain of each
      of the marginal distributions is truncated by the respective
      coordinates of the given rectangle.
      
      If copulae are required (i.e. multivariate distributions with
      uniform marginals) such a generator object can be created by
      means of unur_distr_copula() .

      There are no optional parameters for this method.
   =END
*/

/*---------------------------------------------------------------------------*/
/* Routines for user interface                                               */

/* =ROUTINES */

UNUR_PAR *unur_norta_new( const UNUR_DISTR *distribution );
/* 
   Get default parameters for generator.
*/

/*...........................................................................*/


/* =END */
/*---------------------------------------------------------------------------*/


