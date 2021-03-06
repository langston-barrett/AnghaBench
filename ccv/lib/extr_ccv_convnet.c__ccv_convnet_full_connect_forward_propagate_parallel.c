#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_5__ ;
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ccv_matrix_t ;
struct TYPE_15__ {float* f32; } ;
struct TYPE_18__ {int rows; int cols; TYPE_1__ data; int /*<<< orphan*/  type; } ;
typedef  TYPE_4__ ccv_dense_matrix_t ;
struct TYPE_16__ {scalar_t__ relu; int /*<<< orphan*/  count; } ;
struct TYPE_17__ {TYPE_2__ full_connect; } ;
struct TYPE_19__ {float* bias; TYPE_3__ net; int /*<<< orphan*/  w; } ;
typedef  TYPE_5__ ccv_convnet_layer_t ;

/* Variables and functions */
 int CCV_32F ; 
 int /*<<< orphan*/  CCV_B_TRANSPOSE ; 
 int CCV_C1 ; 
 int CCV_GET_DATA_TYPE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_4__ ccv_dense_matrix (int,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_4__* ccv_dense_matrix_renew (TYPE_4__*,int,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ccv_gemm (TYPE_4__*,TYPE_4__*,int,TYPE_4__*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ **,int /*<<< orphan*/ ) ; 
 float ccv_max (int /*<<< orphan*/ ,float) ; 

__attribute__((used)) static void _ccv_convnet_full_connect_forward_propagate_parallel(ccv_convnet_layer_t* layer, ccv_dense_matrix_t* a, ccv_dense_matrix_t** b)
{
	assert(CCV_GET_DATA_TYPE(a->type) == CCV_32F);
	ccv_dense_matrix_t* db = *b = ccv_dense_matrix_renew(*b, a->rows, layer->net.full_connect.count, CCV_32F | CCV_C1, CCV_32F | CCV_C1, 0);
	// reshape a for gemm
	int i, j;
	float* bptr = db->data.f32;
	for (i = 0; i < db->rows; i++)
	{
		for (j = 0; j < db->cols; j++)
			bptr[j] = layer->bias[j];
		bptr += db->cols;
	}
	ccv_dense_matrix_t dw = ccv_dense_matrix(db->cols, a->cols, CCV_32F | CCV_C1, layer->w, 0);
	ccv_gemm(a, &dw, 1, db, 1, CCV_B_TRANSPOSE, (ccv_matrix_t**)&db, 0); // supply db as matrix C is allowed
	bptr = db->data.f32;
	if (layer->net.full_connect.relu)
		for (i = 0; i < db->rows; i++)
		{
			for (j = 0; j < db->cols; j++)
				bptr[j] = ccv_max(0, bptr[j]); // relu
			bptr += db->cols;
		}
}