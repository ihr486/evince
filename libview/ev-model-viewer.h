/* ev-model-viewer.h
 *  this file is part of evince, a gnome document viewer
 *
 * Copyright (C) 2016 Hiroka Ihara (The Univ. of Tokyo)
 *
 * Evince is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Evince is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef EV_MODEL_VIEWER_H
#define EV_MODEL_VIEWER_H

#include <glib-object.h>
#include <gtk/gtk.h>
#include "ev-media.h"

G_BEGIN_DECLS

#define EV_TYPE_MODEL_VIEWER (ev_model_viewer_get_type())
#define EV_MODEL_VIEWER(object) (G_TYPE_CHECK_INSTANCE_CAST((object), EV_TYPE_MODEL_VIEWER, EvModelViewer))
#define EV_IS_MODEL_VIEWER(object) (G_TYPE_CHECK_INSTANCE_TYPE((object), EV_TYPE_MODEL_VIEWER))
#define EV_MODEL_VIEWER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), EV_TYPE_MODEL_VIEWER, EvModelViewerClass))
#define EV_IS_MODEL_VIEWER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), EV_TYPE_MODEL_VIEWER))
#define EV_MODEL_VIEWER_GET_CLASS(object) (G_TYPE_INSTANCE_GET_CLASS((object), EV_TYPE_MODEL_VIEWER, EvModelViewerClass))

typedef struct _EvModelViewer EvModelViewer;
typedef struct _EvModelViewerClass EvModelViewerClass;

GType ev_model_viewer_get_type (void) G_GNUC_CONST;
GtkWidget *ev_model_viewer_new (EvMedia *media);
EvMedia *ev_model_viewer_get_media (EvModelViewer *viewer);

G_END_DECLS

#endif
