/*************************************************************************/
/*  shape_3d.cpp                                                         */
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

#include "shape_3d_visible.h"

#ifdef DEBUG_ENABLED
void Shape3DVisible::set_use_custom_faces_color(const bool p_use_custom_faces_color) {
	use_custom_faces_color = p_use_custom_faces_color;
	notify_change_to_owners();
	_change_notify("use_custom_faces_color");
}

bool Shape3DVisible::get_use_custom_faces_color() const {
	return use_custom_faces_color;
}

void Shape3DVisible::set_faces_color(const Color &p_faces_color) {
	faces_color = p_faces_color;
	notify_change_to_owners();
	_change_notify("faces_color");
}

Color Shape3DVisible::get_faces_color() const {
	return faces_color;
}

void Shape3DVisible::set_faces_texture(const Ref<Texture> &p_faces_texture) {
	faces_texture = p_faces_texture;
	notify_change_to_owners();
	_change_notify("faces_texture");
}

Ref<Texture> Shape3DVisible::get_faces_texture() const {
	return faces_texture;
}

void Shape3DVisible::set_faces_texture_size(float p_faces_texture_size) {
	faces_texture_size = p_faces_texture_size;
	notify_change_to_owners();
	_change_notify("faces_texture_size");
}

float Shape3DVisible::get_faces_texture_size() const {
	return faces_texture_size;
}

Ref<StandardMaterial3D> Shape3DVisible::get_debug_material(const bool p_disabled) {
	Ref<StandardMaterial3D> mat = memnew(StandardMaterial3D);
	if (use_custom_faces_color) {
		Color alb_col = faces_color;
		if (p_disabled)
			alb_col = Color(alb_col, 0.20);
		mat->set_albedo(alb_col);
		if (!faces_texture.is_null()) {
			mat->set_texture(StandardMaterial3D::TEXTURE_ALBEDO, faces_texture);
			mat->set_flag(StandardMaterial3D::FLAG_UV1_USE_TRIPLANAR, true);
			mat->set_uv1_scale(Vector3(faces_texture_size, faces_texture_size, faces_texture_size));
			mat->set_uv1_triplanar_blend_sharpness(15.0);
		}
	} else {
		mat->set_albedo(Color(0, 0, 1.0, p_disabled ? 0.20 : 0.66));
	}
	mat->set_transparency(StandardMaterial3D::TRANSPARENCY_ALPHA);
	mat->set_shading_mode(StandardMaterial3D::SHADING_MODE_UNSHADED);

	return mat;
}

void Shape3DVisible::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_faces_color", "faces_color"), &Shape3DVisible::set_faces_color);
	ClassDB::bind_method(D_METHOD("get_faces_color"), &Shape3DVisible::get_faces_color);
	ClassDB::bind_method(D_METHOD("set_faces_texture", "faces_texture"), &Shape3DVisible::set_faces_texture);
	ClassDB::bind_method(D_METHOD("get_faces_texture"), &Shape3DVisible::get_faces_texture);
	ClassDB::bind_method(D_METHOD("set_use_custom_faces_color", "use_custom_faces_color"), &Shape3DVisible::set_use_custom_faces_color);
	ClassDB::bind_method(D_METHOD("get_use_custom_faces_color"), &Shape3DVisible::get_use_custom_faces_color);
	ClassDB::bind_method(D_METHOD("set_faces_texture_size", "faces_texture_size"), &Shape3DVisible::set_faces_texture_size);
	ClassDB::bind_method(D_METHOD("get_faces_texture_size"), &Shape3DVisible::get_faces_texture_size);

	ADD_PROPERTY(PropertyInfo(Variant::COLOR, "faces_color"), "set_faces_color", "get_faces_color");
	ADD_PROPERTY((PropertyInfo(Variant::OBJECT, "faces_texture", PROPERTY_HINT_RESOURCE_TYPE, "Texture")), "set_faces_texture", "get_faces_texture");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "use_custom_faces_color"), "set_use_custom_faces_color", "get_use_custom_faces_color");
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "faces_texture_size", PROPERTY_HINT_RANGE, "0,4096,0.01"), "set_faces_texture_size", "get_faces_texture_size");
}

#endif

Shape3DVisible::Shape3DVisible() {
	ERR_PRINT("Default constructor must not be called!");
}

Shape3DVisible::Shape3DVisible(RID p_shape) :
		Shape3D(p_shape) {
#ifdef DEBUG_ENABLED
	Color col = Color().from_hsv(Math::randf(), Math::random(0.8, 1.0), Math::random(0.8, 1.0), 0.66);
	set_faces_color(col);
	set_use_custom_faces_color(true);
	set_faces_texture(Ref<Texture>(nullptr));
	set_faces_texture_size(1.0f);
#endif
}