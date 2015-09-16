#include "Matrix2D.h"


/*
This function sets the matrix Result to the identity matrix
*/
void Matrix2DIdentity(Matrix2D *pResult)
{   int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3;j++)
        {
            if(i==j)
            {pResult ->m[i][j] = 1;}
            else
            {
                pResult->m[i][j]=0;
            }
        }
    }

}

// ---------------------------------------------------------------------------

/*
This functions calculated the transpose matrix of Mtx and saves it in Result
*/
void Matrix2DTranspose(Matrix2D *pResult, Matrix2D *pMtx)
{
pResult-> m[0][0] = pMtx->m[0][0];
pResult-> m[1][0] = pMtx->m[1][1];
pResult-> m[2][2] = pMtx->m[2][2];
pResult-> m[0][1] = pMtx->m[1][0];
pResult-> m[0][2] = pMtx->m[2][0];
pResult-> m[1][2] = pMtx->m[2][1];

}

// ---------------------------------------------------------------------------

/*
This function multiplies Mtx0 with Mtx1 and saves the result in Result
Result = Mtx0*Mtx1
*/
void Matrix2DConcat(Matrix2D *pResult, Matrix2D *pMtx0, Matrix2D *pMtx1)
{
   pResult->m[0][0] = (pMtx0->m[0][0] * pMtx1->m[0][0]) + (pMtx0->m[0][1] * pMtx1->[1][0]) + (pMtx0->[0][2] * pMtx1->[2][0]);
   pResult->m[0][1] = pMtx0->m[0][0] * pMtx1->m[0][1] + pMtx0->m[0][1] * pMtx1->[1][1] + pMtx0->[0][2] * pMtx1->[2][1];
   pResult->m[0][2] = pMtx0->m[0][0] * pMtx1->m[0][2] + pMtx0->m[0][1] * pMtx1->[1][2] + pMtx0->[0][2] * pMtx1->[2][2];
   pResult->m[1][0] = pMtx0->m[1][0] * pMtx1->m[0][0] + pMtx0->m[1][1] * pMtx1->[1][0] + pMtx0->[1][2] * pMtx1->[2][0];
   pResult->m[1][1] = pMtx0->m[1][0] * pMtx1->m[0][1] + pMtx0->m[1][1] * pMtx1->[1][1] + pMtx0->[1][2] * pMtx1->[2][1];
   pResult->m[1][2] = pMtx0->m[1][0] * pMtx1->m[0][2] + pMtx0->m[1][1] * pMtx1->[1][2] + pMtx0->[1][2] * pMtx1->[2][2];
   pResult->m[2][0] = pMtx0->m[2][0] * pMtx1->m[0][0] + pMtx0->m[2][1] * pMtx1->[1][0] + pMtx0->[2][2] * pMtx1->[0][2];
   pResult->m[2][1] = pMtx0->m[2][0] * pMtx1->m[0][1] + pMtx0->m[2][1] * pMtx1->[1][1] + pMtx0->[2][2] * pMtx1->[2][1];
   pResult->m[2][2] = pMtx0->m[2][0] * pMtx1->m[0][2] + pMtx0->m[2][1] * pMtx1->[2][1] + pMtx0->[2][2] * pMtx1->[2][2];
}

// ---------------------------------------------------------------------------

/*
This function creates a translation matrix from x *p y and saves it in Result
*/
void Matrix2DTranslate(Matrix2D *pResult, float x, float y)
{
    int i, j;

    for(i=0; i<3;i++)
    {
        for(j=0; j<2; j++)
        {
            if(i==j)
            {
                pResult->m[i][j] =1;
            }
        }
    }

    pResult->m[2][2]=1;
    pResult->m[0][2]=x;
    pResult->m[1][2]=y;

}

// ---------------------------------------------------------------------------

/*
This function creates a scaling matrix from x *p y and saves it in Result
*/
void Matrix2DScale(Matrix2D *pResult, float x, float y)
{
int i, j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(i==0 && j==0)
            {
                m[i][j]=x;
            }
            else if(i==1 && j==1)
            {
                m[i][j]=y;
            }

            else if(i==2 && j==2)
            {
                m[i][j]=1;
            }
        }
    }

}

// ---------------------------------------------------------------------------

/*
This matrix creates a rotation matrix from "Angle" whose value is in degree.
Save the resultant matrix in Result
*/
void Matrix2DRotDeg(Matrix2D *pResult, float Angle)
{
Angle = (180*Angle)/math.M_PI;
Matrix2DRotRad(pResult, Angle);



}

// ---------------------------------------------------------------------------

/*
This matrix creates a rotation matrix from "Angle" whose value is in radian.
Save the resultant matrix in Result
*/
void Matrix2DRotRad(Matrix2D *pResult, float Angle)
{

    pResult->m[0][0]=math.cos(Angle);
    pResult->m[0][1]=(-1)*math.sin(Angle);
    pResult->m[0][2]=0;
    pResult->m[1][0]=math.sin(Angle);
    pResult->m[1][1]=pResult->m[0][0];
    pResult->m[1][2]=0;
    pResult->m[2][0]=0;
    pResult->m[2][1]=0;
    pResult->m[2][2]=1;


}

// ---------------------------------------------------------------------------

/*
This function multiplies the matrix Mtx with the vector Vec and saves the result in Result
Result = Mtx * Vec
*/
void Matrix2DMultVec(Vector2D *pResult, Matrix2D *pMtx, Vector2D *pVec)
{

    float weight = pMtx->m[2][0] + pMtx->[2][1] + pMtx->[2][2];

    pResult->x = (pMtx->m[0][0] * pVec->x + pMtx->m[0][1] * pVec->y + pMtx->m[0][2])/weight;
    pResult->y = (pMtx->m[1][0] * pVec->x + pMtx->m[1][1] * pVec->y + pMtx->m[1][2])/weight;

}

// ---------------------------------------------------------------------------
