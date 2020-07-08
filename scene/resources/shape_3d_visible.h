/*************************************************************************/
/*  shape_3d_visible.h                                                   */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2020 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2020 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#ifndef SHAPE_3D_VISIBLE_H
#define SHAPE_3D_VISIBLE_H

#include "core/resource.h"
#include "shape_3d.h"

#ifdef DEBUG_ENABLED
#include "material.h"
#include "texture.h"
#endif

class Shape3DVisible : public Shape3D {
	GDCLASS(Shape3DVisible, Shape3D);
	OBJ_SAVE_TYPE(Shape3DVisible);

#ifdef DEBUG_ENABLED
	bool use_custom_faces_color;
	Color faces_color;
	Ref<Texture> faces_texture;
	float faces_texture_size;
#endif

protected:
	Shape3DVisible(RID p_shape);

#ifdef DEBUG_ENABLED
	static void _bind_methods();

public:
	void set_use_custom_faces_color(bool p_use_custom_faces_color);
	bool get_use_custom_faces_color() const;
	void set_faces_texture(const Ref<Texture> &p_faces_texture);
	Ref<Texture> get_faces_texture() const;
	void set_faces_color(const Color &p_faces_color);
	Color get_faces_color() const;
	void set_faces_texture_size(float p_faces_texture_size);
	float get_faces_texture_size() const;
	Ref<StandardMaterial3D> get_debug_material(bool p_disabled);
	virtual Ref<ArrayMesh> get_debug_arraymesh_faces() const = 0;
#endif

	Shape3DVisible();
};

#endif // SHAPE_3D_VISIBLE_H
