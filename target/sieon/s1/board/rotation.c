/******************************************************************************
 * Copyright 2022 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#include <firmament.h>
#include "module/math/rotation.h"

void icm42688_rotate_to_frd(float* data, uint32_t dev_id)
{
    rotation(ROTATION_YAW_270, data, data + 1, data + 2);
}

void bmi088_rotate_to_frd(float* data, uint32_t dev_id)
{
    rotation(ROTATION_YAW_180, data, data + 1, data + 2);
}

void bmm150_rotate_to_frd(float* data, uint32_t dev_id)
{
    rotation(ROTATION_PITCH_180, data, data + 1, data + 2);
}

void qmc5883l_rotate_to_frd(float* data)
{
    rotation(ROTATION_YAW_90, data, data + 1, data + 2);
}

