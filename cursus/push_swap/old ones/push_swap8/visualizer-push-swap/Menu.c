/* Menu.c generated by valac 0.57.0.224-bccf, the Vala compiler
 * generated from Menu.vala, do not modify */

/*valac main.vala Window.vala Menu.vala --pkg=gtk+-3.0*/

#include <glib-object.h>
#include <gtk/gtk.h>
#include <glib.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>

#if !defined(VALA_EXTERN)
#if defined(_WIN32) || defined(__CYGWIN__)
#define VALA_EXTERN __declspec(dllexport) extern
#elif __GNUC__ >= 4
#define VALA_EXTERN __attribute__((visibility("default"))) extern
#else
#define VALA_EXTERN extern
#endif
#endif

typedef enum  {
	TYPE_EVENT_CONTINUE,
	TYPE_EVENT_NEW,
	TYPE_EVENT_STOP,
	TYPE_EVENT_STEP,
	TYPE_EVENT_BACKSTEP,
	TYPE_EVENT_REVERSE,
	TYPE_EVENT_FORWARD
} TypeEvent;

#define TYPE_TYPE_EVENT (type_event_get_type ())

#define TYPE_MENU (menu_get_type ())
#define MENU(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_MENU, Menu))
#define MENU_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_MENU, MenuClass))
#define IS_MENU(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_MENU))
#define IS_MENU_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_MENU))
#define MENU_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_MENU, MenuClass))

typedef struct _Menu Menu;
typedef struct _MenuClass MenuClass;
typedef struct _MenuPrivate MenuPrivate;
enum  {
	MENU_0_PROPERTY,
	MENU_NUM_PROPERTIES
};
static GParamSpec* menu_properties[MENU_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
enum  {
	MENU_ON_EVENT_SIGNAL,
	MENU_ON_CHANGE_SPEED_SIGNAL,
	MENU_NUM_SIGNALS
};
static guint menu_signals[MENU_NUM_SIGNALS] = {0};

struct _Menu {
	GtkBox parent_instance;
	MenuPrivate * priv;
};

struct _MenuClass {
	GtkBoxClass parent_class;
};

struct _MenuPrivate {
	GtkSpinButton* b_spin;
	GtkButton* b_step;
	GtkButton* b_backstep;
	GtkButton* b_nouveau;
	GtkToggleButton* t_continue;
	GtkToggleButton* t_reverse;
	GtkImage* i_reverse;
	GtkLabel* l_count;
};

static gint Menu_private_offset;
static gpointer menu_parent_class = NULL;

VALA_EXTERN GType type_event_get_type (void) G_GNUC_CONST ;
VALA_EXTERN GType menu_get_type (void) G_GNUC_CONST ;
G_DEFINE_AUTOPTR_CLEANUP_FUNC (Menu, g_object_unref)
VALA_EXTERN Menu* menu_new (void);
VALA_EXTERN Menu* menu_construct (GType object_type);
static void menu_init_menu (Menu* self,
                     GtkBox* box);
static void menu_init_event (Menu* self);
VALA_EXTERN void menu_iterate_count (Menu* self,
                         const gchar* line,
                         gint count);
VALA_EXTERN void menu_scaling_mode (Menu* self);
VALA_EXTERN void menu_refresh_speed (Menu* self);
static void _vala_lambda6_ (Menu* self);
static void __vala_lambda6__gtk_button_clicked (GtkButton* _sender,
                                         gpointer self);
static void _vala_lambda7_ (Menu* self);
static void __vala_lambda7__gtk_button_clicked (GtkButton* _sender,
                                         gpointer self);
static void _vala_lambda8_ (Menu* self);
static void __vala_lambda8__gtk_button_clicked (GtkButton* _sender,
                                         gpointer self);
static void _vala_lambda9_ (Menu* self);
static void __vala_lambda9__gtk_toggle_button_toggled (GtkToggleButton* _sender,
                                                gpointer self);
static void _vala_lambda10_ (Menu* self);
static void __vala_lambda10__gtk_toggle_button_toggled (GtkToggleButton* _sender,
                                                 gpointer self);
static void _vala_lambda11_ (Menu* self);
static void __vala_lambda11__gtk_spin_button_value_changed (GtkSpinButton* _sender,
                                                     gpointer self);
static void menu_finalize (GObject * obj);
static GType menu_get_type_once (void);

static GType
type_event_get_type_once (void)
{
	static const GEnumValue values[] = {{TYPE_EVENT_CONTINUE, "TYPE_EVENT_CONTINUE", "continue"}, {TYPE_EVENT_NEW, "TYPE_EVENT_NEW", "new"}, {TYPE_EVENT_STOP, "TYPE_EVENT_STOP", "stop"}, {TYPE_EVENT_STEP, "TYPE_EVENT_STEP", "step"}, {TYPE_EVENT_BACKSTEP, "TYPE_EVENT_BACKSTEP", "backstep"}, {TYPE_EVENT_REVERSE, "TYPE_EVENT_REVERSE", "reverse"}, {TYPE_EVENT_FORWARD, "TYPE_EVENT_FORWARD", "forward"}, {0, NULL, NULL}};
	GType type_event_type_id;
	type_event_type_id = g_enum_register_static ("TypeEvent", values);
	return type_event_type_id;
}

GType
type_event_get_type (void)
{
	static volatile gsize type_event_type_id__once = 0;
	if (g_once_init_enter (&type_event_type_id__once)) {
		GType type_event_type_id;
		type_event_type_id = type_event_get_type_once ();
		g_once_init_leave (&type_event_type_id__once, type_event_type_id);
	}
	return type_event_type_id__once;
}

static inline gpointer
menu_get_instance_private (Menu* self)
{
	return G_STRUCT_MEMBER_P (self, Menu_private_offset);
}

Menu*
menu_construct (GType object_type)
{
	Menu * self = NULL;
	gchar* _tmp0_;
	GtkButton* _tmp1_ = NULL;
	GtkBox* box_step = NULL;
	GtkBox* _tmp2_;
	gchar* _tmp3_;
	GtkButton* _tmp4_ = NULL;
	GtkButton* _tmp5_;
	GtkImage* _tmp6_;
	GtkImage* _tmp7_;
	GtkButton* _tmp8_;
	GtkStyleContext* _tmp9_;
	gchar* _tmp10_;
	GtkButton* _tmp11_ = NULL;
	GtkButton* _tmp12_;
	GtkImage* _tmp13_;
	GtkImage* _tmp14_;
	GtkButton* _tmp15_;
	GtkStyleContext* _tmp16_;
	GtkButton* _tmp17_;
	GtkButton* _tmp18_;
	GtkToggleButton* _tmp19_ = NULL;
	GtkToggleButton* _tmp20_ = NULL;
	GtkImage* _tmp21_;
	GtkToggleButton* _tmp22_;
	GtkImage* _tmp23_;
	GtkToggleButton* _tmp24_;
	GtkToggleButton* _tmp25_;
	GtkLabel* _tmp26_;
	GtkSpinButton* _tmp27_ = NULL;
	GtkButton* _tmp28_;
	self = (Menu*) g_object_new (object_type, "orientation", GTK_ORIENTATION_VERTICAL, "spacing", 8, "name", "menu", NULL);
	gtk_widget_set_vexpand ((GtkWidget*) G_TYPE_CHECK_INSTANCE_CAST (self, gtk_box_get_type (), GtkBox), TRUE);
	_tmp0_ = g_strdup ("new");
	_tmp1_ = (GtkButton*) gtk_button_new_with_label ("New");
	gtk_widget_set_name ((GtkWidget*) _tmp1_, _tmp0_);
	_g_free0 (_tmp0_);
	g_object_ref_sink (_tmp1_);
	_g_object_unref0 (self->priv->b_nouveau);
	self->priv->b_nouveau = _tmp1_;
	_tmp2_ = (GtkBox*) gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
	g_object_ref_sink (_tmp2_);
	box_step = _tmp2_;
	_tmp3_ = g_strdup ("step");
	_tmp4_ = (GtkButton*) gtk_button_new ();
	gtk_widget_set_name ((GtkWidget*) _tmp4_, _tmp3_);
	_g_free0 (_tmp3_);
	g_object_ref_sink (_tmp4_);
	_g_object_unref0 (self->priv->b_step);
	self->priv->b_step = _tmp4_;
	_tmp5_ = self->priv->b_step;
	_tmp6_ = (GtkImage*) gtk_image_new_from_icon_name ("pan-end-symbolic", (GtkIconSize) GTK_ICON_SIZE_BUTTON);
	g_object_ref_sink (_tmp6_);
	_tmp7_ = _tmp6_;
	g_object_set ((GtkContainer*) _tmp5_, "child", (GtkWidget*) _tmp7_, NULL);
	_g_object_unref0 (_tmp7_);
	_tmp8_ = self->priv->b_step;
	_tmp9_ = gtk_widget_get_style_context ((GtkWidget*) _tmp8_);
	gtk_style_context_add_class (_tmp9_, "right");
	_tmp10_ = g_strdup ("backstep");
	_tmp11_ = (GtkButton*) gtk_button_new ();
	gtk_widget_set_name ((GtkWidget*) _tmp11_, _tmp10_);
	_g_free0 (_tmp10_);
	g_object_ref_sink (_tmp11_);
	_g_object_unref0 (self->priv->b_backstep);
	self->priv->b_backstep = _tmp11_;
	_tmp12_ = self->priv->b_backstep;
	_tmp13_ = (GtkImage*) gtk_image_new_from_icon_name ("pan-start-symbolic", (GtkIconSize) GTK_ICON_SIZE_BUTTON);
	g_object_ref_sink (_tmp13_);
	_tmp14_ = _tmp13_;
	g_object_set ((GtkContainer*) _tmp12_, "child", (GtkWidget*) _tmp14_, NULL);
	_g_object_unref0 (_tmp14_);
	_tmp15_ = self->priv->b_backstep;
	_tmp16_ = gtk_widget_get_style_context ((GtkWidget*) _tmp15_);
	gtk_style_context_add_class (_tmp16_, "left");
	_tmp17_ = self->priv->b_backstep;
	gtk_box_pack_start (box_step, (GtkWidget*) _tmp17_, TRUE, TRUE, (guint) 0);
	_tmp18_ = self->priv->b_step;
	gtk_box_pack_start (box_step, (GtkWidget*) _tmp18_, TRUE, TRUE, (guint) 0);
	_tmp19_ = (GtkToggleButton*) gtk_toggle_button_new_with_label ("Continue");
	gtk_toggle_button_set_active (_tmp19_, TRUE);
	g_object_ref_sink (_tmp19_);
	_g_object_unref0 (self->priv->t_continue);
	self->priv->t_continue = _tmp19_;
	_tmp20_ = (GtkToggleButton*) gtk_toggle_button_new ();
	gtk_toggle_button_set_active (_tmp20_, TRUE);
	g_object_ref_sink (_tmp20_);
	_g_object_unref0 (self->priv->t_reverse);
	self->priv->t_reverse = _tmp20_;
	_tmp21_ = (GtkImage*) gtk_image_new_from_icon_name ("media-skip-backward-symbolic", (GtkIconSize) GTK_ICON_SIZE_BUTTON);
	g_object_ref_sink (_tmp21_);
	_g_object_unref0 (self->priv->i_reverse);
	self->priv->i_reverse = _tmp21_;
	_tmp22_ = self->priv->t_reverse;
	_tmp23_ = self->priv->i_reverse;
	g_object_set ((GtkContainer*) _tmp22_, "child", (GtkWidget*) _tmp23_, NULL);
	_tmp24_ = self->priv->t_reverse;
	gtk_widget_set_valign ((GtkWidget*) _tmp24_, GTK_ALIGN_END);
	_tmp25_ = self->priv->t_reverse;
	gtk_widget_set_vexpand ((GtkWidget*) _tmp25_, TRUE);
	_tmp26_ = (GtkLabel*) gtk_label_new ("0");
	g_object_ref_sink (_tmp26_);
	_g_object_unref0 (self->priv->l_count);
	self->priv->l_count = _tmp26_;
	_tmp27_ = (GtkSpinButton*) gtk_spin_button_new_with_range (1.0, 7.0, 1.0);
	gtk_spin_button_set_value (_tmp27_, 3.0);
	g_object_ref_sink (_tmp27_);
	_g_object_unref0 (self->priv->b_spin);
	self->priv->b_spin = _tmp27_;
	_tmp28_ = self->priv->b_step;
	gtk_widget_set_visible ((GtkWidget*) _tmp28_, FALSE);
	menu_init_menu (self, box_step);
	menu_init_event (self);
	_g_object_unref0 (box_step);
	return self;
}

Menu*
menu_new (void)
{
	return menu_construct (TYPE_MENU);
}

static void
menu_init_menu (Menu* self,
                GtkBox* box)
{
	GtkButton* _tmp0_;
	GtkSpinButton* _tmp1_;
	GtkToggleButton* _tmp2_;
	GtkLabel* _tmp3_;
	GtkToggleButton* _tmp4_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (box != NULL);
	_tmp0_ = self->priv->b_nouveau;
	gtk_box_pack_start (G_TYPE_CHECK_INSTANCE_CAST (self, gtk_box_get_type (), GtkBox), (GtkWidget*) _tmp0_, FALSE, FALSE, (guint) 0);
	_tmp1_ = self->priv->b_spin;
	gtk_box_pack_start (G_TYPE_CHECK_INSTANCE_CAST (self, gtk_box_get_type (), GtkBox), (GtkWidget*) _tmp1_, FALSE, FALSE, (guint) 0);
	_tmp2_ = self->priv->t_continue;
	gtk_box_pack_start (G_TYPE_CHECK_INSTANCE_CAST (self, gtk_box_get_type (), GtkBox), (GtkWidget*) _tmp2_, FALSE, FALSE, (guint) 0);
	gtk_box_pack_start (G_TYPE_CHECK_INSTANCE_CAST (self, gtk_box_get_type (), GtkBox), (GtkWidget*) box, FALSE, FALSE, (guint) 0);
	_tmp3_ = self->priv->l_count;
	gtk_box_pack_start (G_TYPE_CHECK_INSTANCE_CAST (self, gtk_box_get_type (), GtkBox), (GtkWidget*) _tmp3_, FALSE, FALSE, (guint) 0);
	_tmp4_ = self->priv->t_reverse;
	gtk_box_pack_start (G_TYPE_CHECK_INSTANCE_CAST (self, gtk_box_get_type (), GtkBox), (GtkWidget*) _tmp4_, TRUE, TRUE, (guint) 5);
}

static const gchar*
string_to_string (const gchar* self)
{
	const gchar* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}

void
menu_iterate_count (Menu* self,
                    const gchar* line,
                    gint count)
{
	GtkLabel* _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_;
	gchar* _tmp3_;
	gchar* _tmp4_;
	gchar* _tmp5_;
	g_return_if_fail (self != NULL);
	g_return_if_fail (line != NULL);
	_tmp0_ = self->priv->l_count;
	_tmp1_ = string_to_string (line);
	_tmp2_ = g_strdup_printf ("%i", count);
	_tmp3_ = _tmp2_;
	_tmp4_ = g_strconcat (_tmp1_, " ", _tmp3_, NULL);
	_tmp5_ = _tmp4_;
	gtk_label_set_label (_tmp0_, _tmp5_);
	_g_free0 (_tmp5_);
	_g_free0 (_tmp3_);
}

void
menu_scaling_mode (Menu* self)
{
	GtkToggleButton* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->t_continue;
	gtk_toggle_button_set_active (_tmp0_, TRUE);
}

void
menu_refresh_speed (Menu* self)
{
	GtkSpinButton* _tmp0_;
	gdouble _tmp1_;
	gdouble _tmp2_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->b_spin;
	_tmp1_ = gtk_spin_button_get_value (_tmp0_);
	_tmp2_ = _tmp1_;
	g_signal_emit (self, menu_signals[MENU_ON_CHANGE_SPEED_SIGNAL], 0, (gint) _tmp2_);
}

static void
_vala_lambda6_ (Menu* self)
{
	g_signal_emit (self, menu_signals[MENU_ON_EVENT_SIGNAL], 0, TYPE_EVENT_NEW);
}

static void
__vala_lambda6__gtk_button_clicked (GtkButton* _sender,
                                    gpointer self)
{
	_vala_lambda6_ ((Menu*) self);
}

static void
_vala_lambda7_ (Menu* self)
{
	g_signal_emit (self, menu_signals[MENU_ON_EVENT_SIGNAL], 0, TYPE_EVENT_STEP);
}

static void
__vala_lambda7__gtk_button_clicked (GtkButton* _sender,
                                    gpointer self)
{
	_vala_lambda7_ ((Menu*) self);
}

static void
_vala_lambda8_ (Menu* self)
{
	g_signal_emit (self, menu_signals[MENU_ON_EVENT_SIGNAL], 0, TYPE_EVENT_BACKSTEP);
}

static void
__vala_lambda8__gtk_button_clicked (GtkButton* _sender,
                                    gpointer self)
{
	_vala_lambda8_ ((Menu*) self);
}

static void
_vala_lambda9_ (Menu* self)
{
	GtkButton* _tmp0_;
	GtkButton* _tmp1_;
	gboolean _tmp2_;
	gboolean _tmp3_;
	GtkButton* _tmp4_;
	GtkButton* _tmp5_;
	gboolean _tmp6_;
	gboolean _tmp7_;
	GtkToggleButton* _tmp8_;
	_tmp0_ = self->priv->b_step;
	_tmp1_ = self->priv->b_step;
	_tmp2_ = gtk_widget_get_visible ((GtkWidget*) _tmp1_);
	_tmp3_ = _tmp2_;
	gtk_widget_set_visible ((GtkWidget*) _tmp0_, !_tmp3_);
	_tmp4_ = self->priv->b_backstep;
	_tmp5_ = self->priv->b_backstep;
	_tmp6_ = gtk_widget_get_visible ((GtkWidget*) _tmp5_);
	_tmp7_ = _tmp6_;
	gtk_widget_set_visible ((GtkWidget*) _tmp4_, !_tmp7_);
	_tmp8_ = self->priv->t_continue;
	if (gtk_toggle_button_get_active (_tmp8_)) {
		GtkToggleButton* _tmp9_;
		_tmp9_ = self->priv->t_continue;
		gtk_button_set_label ((GtkButton*) _tmp9_, "Continue");
		g_signal_emit (self, menu_signals[MENU_ON_EVENT_SIGNAL], 0, TYPE_EVENT_STOP);
	} else {
		GtkToggleButton* _tmp10_;
		_tmp10_ = self->priv->t_continue;
		gtk_button_set_label ((GtkButton*) _tmp10_, "Stop");
		g_signal_emit (self, menu_signals[MENU_ON_EVENT_SIGNAL], 0, TYPE_EVENT_CONTINUE);
	}
}

static void
__vala_lambda9__gtk_toggle_button_toggled (GtkToggleButton* _sender,
                                           gpointer self)
{
	_vala_lambda9_ ((Menu*) self);
}

static void
_vala_lambda10_ (Menu* self)
{
	GtkToggleButton* _tmp0_;
	_tmp0_ = self->priv->t_reverse;
	if (gtk_toggle_button_get_active (_tmp0_)) {
		GtkImage* _tmp1_;
		_tmp1_ = self->priv->i_reverse;
		g_object_set (_tmp1_, "icon-name", "media-skip-backward-symbolic", NULL);
		g_signal_emit (self, menu_signals[MENU_ON_EVENT_SIGNAL], 0, TYPE_EVENT_FORWARD);
	} else {
		GtkImage* _tmp2_;
		_tmp2_ = self->priv->i_reverse;
		g_object_set (_tmp2_, "icon-name", "media-skip-forward-symbolic", NULL);
		g_signal_emit (self, menu_signals[MENU_ON_EVENT_SIGNAL], 0, TYPE_EVENT_REVERSE);
	}
}

static void
__vala_lambda10__gtk_toggle_button_toggled (GtkToggleButton* _sender,
                                            gpointer self)
{
	_vala_lambda10_ ((Menu*) self);
}

static void
_vala_lambda11_ (Menu* self)
{
	GtkSpinButton* _tmp0_;
	gdouble _tmp1_;
	gdouble _tmp2_;
	_tmp0_ = self->priv->b_spin;
	_tmp1_ = gtk_spin_button_get_value (_tmp0_);
	_tmp2_ = _tmp1_;
	g_signal_emit (self, menu_signals[MENU_ON_CHANGE_SPEED_SIGNAL], 0, (gint) _tmp2_);
}

static void
__vala_lambda11__gtk_spin_button_value_changed (GtkSpinButton* _sender,
                                                gpointer self)
{
	_vala_lambda11_ ((Menu*) self);
}

static void
menu_init_event (Menu* self)
{
	GtkButton* _tmp0_;
	GtkButton* _tmp1_;
	GtkButton* _tmp2_;
	GtkToggleButton* _tmp3_;
	GtkToggleButton* _tmp4_;
	GtkSpinButton* _tmp5_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->b_nouveau;
	g_signal_connect_object (_tmp0_, "clicked", (GCallback) __vala_lambda6__gtk_button_clicked, self, 0);
	_tmp1_ = self->priv->b_step;
	g_signal_connect_object (_tmp1_, "clicked", (GCallback) __vala_lambda7__gtk_button_clicked, self, 0);
	_tmp2_ = self->priv->b_backstep;
	g_signal_connect_object (_tmp2_, "clicked", (GCallback) __vala_lambda8__gtk_button_clicked, self, 0);
	_tmp3_ = self->priv->t_continue;
	g_signal_connect_object (_tmp3_, "toggled", (GCallback) __vala_lambda9__gtk_toggle_button_toggled, self, 0);
	_tmp4_ = self->priv->t_reverse;
	g_signal_connect_object (_tmp4_, "toggled", (GCallback) __vala_lambda10__gtk_toggle_button_toggled, self, 0);
	_tmp5_ = self->priv->b_spin;
	g_signal_connect_object (_tmp5_, "value-changed", (GCallback) __vala_lambda11__gtk_spin_button_value_changed, self, 0);
}

static void
menu_class_init (MenuClass * klass,
                 gpointer klass_data)
{
	menu_parent_class = g_type_class_peek_parent (klass);
	g_type_class_adjust_private_offset (klass, &Menu_private_offset);
	G_OBJECT_CLASS (klass)->finalize = menu_finalize;
	menu_signals[MENU_ON_EVENT_SIGNAL] = g_signal_new ("on-event", TYPE_MENU, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__ENUM, G_TYPE_NONE, 1, TYPE_TYPE_EVENT);
	menu_signals[MENU_ON_CHANGE_SPEED_SIGNAL] = g_signal_new ("on-change-speed", TYPE_MENU, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__INT, G_TYPE_NONE, 1, G_TYPE_INT);
}

static void
menu_instance_init (Menu * self,
                    gpointer klass)
{
	self->priv = menu_get_instance_private (self);
}

static void
menu_finalize (GObject * obj)
{
	Menu * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_MENU, Menu);
	_g_object_unref0 (self->priv->b_spin);
	_g_object_unref0 (self->priv->b_step);
	_g_object_unref0 (self->priv->b_backstep);
	_g_object_unref0 (self->priv->b_nouveau);
	_g_object_unref0 (self->priv->t_continue);
	_g_object_unref0 (self->priv->t_reverse);
	_g_object_unref0 (self->priv->i_reverse);
	_g_object_unref0 (self->priv->l_count);
	G_OBJECT_CLASS (menu_parent_class)->finalize (obj);
}

static GType
menu_get_type_once (void)
{
	static const GTypeInfo g_define_type_info = { sizeof (MenuClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) menu_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Menu), 0, (GInstanceInitFunc) menu_instance_init, NULL };
	GType menu_type_id;
	menu_type_id = g_type_register_static (gtk_box_get_type (), "Menu", &g_define_type_info, 0);
	Menu_private_offset = g_type_add_instance_private (menu_type_id, sizeof (MenuPrivate));
	return menu_type_id;
}

GType
menu_get_type (void)
{
	static volatile gsize menu_type_id__once = 0;
	if (g_once_init_enter (&menu_type_id__once)) {
		GType menu_type_id;
		menu_type_id = menu_get_type_once ();
		g_once_init_leave (&menu_type_id__once, menu_type_id);
	}
	return menu_type_id__once;
}

