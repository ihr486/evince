/* ev-model-viewer.c
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

#include "config.h"

#include "ev-model-viewer.h"

#if defined (GDK_WINDOWING_X11)
#include <gdk/gdkx.h>
#elif defined (GDK_WINDOWING_WIN32)
#include <gdk/gdkwin32.h>
#endif

struct _EvModelViewer {
    GtkBox parent;
    EvMedia *media;
};

struct _EvModelViewerClass {
    GtkBoxClass parent_class;
};

G_DEFINE_TYPE (EvModelViewer, ev_model_viewer, GTK_TYPE_BOX)

static void
ev_model_viewer_init (EvModelViewer *viewer)
{
}

static void
ev_model_viewer_constructed (GObject *object)
{
    EvModelViewer *viewer = EV_MODEL_VIEWER (object);

    G_OBJECT_CLASS (ev_model_viewer_parent_class)->constructed (object);
}

static void
ev_model_viewer_dispose (GObject *object)
{
    EvModelViewer *viewer = EV_MODEL_VIEWER (object);

    g_clear_object (&viewer->media);

    G_OBJECT_CLASS (ev_model_viewer_parent_class)->dispose (object);
}

static void
ev_model_viewer_class_init (EvModelViewerClass *klass)
{
    GObjectClass *g_object_class = G_OBJECT_CLASS (klass);
    GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (klass);

    g_object_class->constructed = ev_model_viewer_constructed;
    g_object_class->dispose = ev_model_viewer_dispose;
}

GtkWidget *
ev_model_viewer_new (EvMedia *media)
{
    g_return_val_if_fail (EV_IS_ARTWORK3D (media), NULL);

    EvModelViewer *viewer = EV_MODEL_VIEWER (g_object_new (EV_TYPE_MODEL_VIEWER, NULL));

    viewer->media = media;
    g_object_ref (media);

    printf("Model path: %s\n", ev_media_get_uri (media));

    return GTK_WIDGET (viewer);
}

EvMedia *
ev_model_viewer_get_media (EvModelViewer *viewer)
{
    g_return_val_if_fail (EV_IS_MODEL_VIEWER (viewer), NULL);

    return viewer->media;
}
