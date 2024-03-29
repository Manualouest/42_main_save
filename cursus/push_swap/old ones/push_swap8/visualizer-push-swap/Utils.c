/* Utils.c generated by valac 0.57.0.224-bccf, the Vala compiler
 * generated from Utils.vala, do not modify */

#include <gio/gio.h>
#include <glib.h>

#if !defined(VALA_EXTERN)
#if defined(_WIN32) || defined(__CYGWIN__)
#define VALA_EXTERN __declspec(dllexport) extern
#elif __GNUC__ >= 4
#define VALA_EXTERN __attribute__((visibility("default"))) extern
#else
#define VALA_EXTERN extern
#endif
#endif

typedef struct _UtilsSleepData UtilsSleepData;
typedef struct _Block2Data Block2Data;
#define _g_thread_unref0(var) ((var == NULL) ? NULL : (var = (g_thread_unref (var), NULL)))
typedef struct _UtilsUsleepData UtilsUsleepData;
#define _g_rand_free0(var) ((var == NULL) ? NULL : (var = (g_rand_free (var), NULL)))

struct _UtilsSleepData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GTask* _async_result;
	gint time;
};

struct _Block2Data {
	int _ref_count_;
	gint time;
	gpointer _async_data_;
};

struct _UtilsUsleepData {
	int _state_;
	GObject* _source_object_;
	GAsyncResult* _res_;
	GTask* _async_result;
	gint time;
	Block2Data* _data2_;
	GThread* _tmp0_;
	GThread* _tmp1_;
};

static void utils_sleep_data_free (gpointer _data);
VALA_EXTERN void utils_sleep (gint time,
                  GAsyncReadyCallback _callback_,
                  gpointer _user_data_);
VALA_EXTERN void utils_sleep_finish (GAsyncResult* _res_);
static gboolean utils_sleep_co (UtilsSleepData* _data_);
static gboolean _utils_sleep_co_gsource_func (gpointer self);
static void utils_usleep_data_free (gpointer _data);
VALA_EXTERN void utils_usleep (gint time,
                   GAsyncReadyCallback _callback_,
                   gpointer _user_data_);
VALA_EXTERN void utils_usleep_finish (GAsyncResult* _res_);
static gboolean utils_usleep_co (UtilsUsleepData* _data_);
static Block2Data* block2_data_ref (Block2Data* _data2_);
static void block2_data_unref (void * _userdata_);
static void _vala_lambda12_ (Block2Data* _data2_);
static gboolean _utils_usleep_co_gsource_func (gpointer self);
static gpointer __vala_lambda12__gthread_func (gpointer self);
VALA_EXTERN gint* utils_get_random_tab (gint size,
                            gint* result_length1);
static gboolean _vala_int_array_contains (gint * stack,
                                   gssize stack_length,
                                   const gint needle);

static void
utils_sleep_data_free (gpointer _data)
{
	UtilsSleepData* _data_;
	_data_ = _data;
	g_slice_free (UtilsSleepData, _data_);
}

void
utils_sleep (gint time,
             GAsyncReadyCallback _callback_,
             gpointer _user_data_)
{
	UtilsSleepData* _data_;
	_data_ = g_slice_new0 (UtilsSleepData);
	_data_->_async_result = g_task_new (NULL, NULL, _callback_, _user_data_);
	g_task_set_task_data (_data_->_async_result, _data_, utils_sleep_data_free);
	_data_->time = time;
	utils_sleep_co (_data_);
}

void
utils_sleep_finish (GAsyncResult* _res_)
{
	UtilsSleepData* _data_;
	_data_ = g_task_propagate_pointer (G_TASK (_res_), NULL);
}

static gboolean
_utils_sleep_co_gsource_func (gpointer self)
{
	gboolean result;
	result = utils_sleep_co (self);
	return result;
}

static gboolean
utils_sleep_co (UtilsSleepData* _data_)
{
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) _data_->time, _utils_sleep_co_gsource_func, _data_, NULL);
	_data_->_state_ = 1;
	return FALSE;
	_state_1:
	;
	g_task_return_pointer (_data_->_async_result, _data_, NULL);
	if (_data_->_state_ != 0) {
		while (!g_task_get_completed (_data_->_async_result)) {
			g_main_context_iteration (g_task_get_context (_data_->_async_result), TRUE);
		}
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}

static void
utils_usleep_data_free (gpointer _data)
{
	UtilsUsleepData* _data_;
	_data_ = _data;
	g_slice_free (UtilsUsleepData, _data_);
}

void
utils_usleep (gint time,
              GAsyncReadyCallback _callback_,
              gpointer _user_data_)
{
	UtilsUsleepData* _data_;
	_data_ = g_slice_new0 (UtilsUsleepData);
	_data_->_async_result = g_task_new (NULL, NULL, _callback_, _user_data_);
	g_task_set_task_data (_data_->_async_result, _data_, utils_usleep_data_free);
	_data_->time = time;
	utils_usleep_co (_data_);
}

void
utils_usleep_finish (GAsyncResult* _res_)
{
	UtilsUsleepData* _data_;
	_data_ = g_task_propagate_pointer (G_TASK (_res_), NULL);
}

static Block2Data*
block2_data_ref (Block2Data* _data2_)
{
	g_atomic_int_inc (&_data2_->_ref_count_);
	return _data2_;
}

static void
block2_data_unref (void * _userdata_)
{
	Block2Data* _data2_;
	_data2_ = (Block2Data*) _userdata_;
	if (g_atomic_int_dec_and_test (&_data2_->_ref_count_)) {
		g_slice_free (Block2Data, _data2_);
	}
}

static gboolean
_utils_usleep_co_gsource_func (gpointer self)
{
	gboolean result;
	result = utils_usleep_co (self);
	return result;
}

static void
_vala_lambda12_ (Block2Data* _data2_)
{
	g_usleep ((gulong) _data2_->time);
	g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, _utils_usleep_co_gsource_func, _data2_->_async_data_, NULL);
}

static gpointer
__vala_lambda12__gthread_func (gpointer self)
{
	gpointer result;
	_vala_lambda12_ (self);
	result = NULL;
	block2_data_unref (self);
	return result;
}

static gboolean
utils_usleep_co (UtilsUsleepData* _data_)
{
	switch (_data_->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	_data_->_data2_ = g_slice_new0 (Block2Data);
	_data_->_data2_->_ref_count_ = 1;
	_data_->_data2_->time = _data_->time;
	_data_->_data2_->_async_data_ = _data_;
	if (_data_->_data2_->time != 0) {
		_data_->_tmp0_ = g_thread_new (NULL, __vala_lambda12__gthread_func, block2_data_ref (_data_->_data2_));
		_data_->_tmp1_ = _data_->_tmp0_;
		_g_thread_unref0 (_data_->_tmp1_);
	} else {
		g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, _utils_usleep_co_gsource_func, _data_, NULL);
	}
	_data_->_state_ = 1;
	return FALSE;
	_state_1:
	;
	block2_data_unref (_data_->_data2_);
	_data_->_data2_ = NULL;
	g_task_return_pointer (_data_->_async_result, _data_, NULL);
	if (_data_->_state_ != 0) {
		while (!g_task_get_completed (_data_->_async_result)) {
			g_main_context_iteration (g_task_get_context (_data_->_async_result), TRUE);
		}
	}
	g_object_unref (_data_->_async_result);
	return FALSE;
}

static gboolean
_vala_int_array_contains (gint * stack,
                          gssize stack_length,
                          const gint needle)
{
	gssize i;
	for (i = 0; i < stack_length; i++) {
		if (needle == stack[i]) {
			return TRUE;
		}
	}
	return FALSE;
}

gint*
utils_get_random_tab (gint size,
                      gint* result_length1)
{
	GRand* rand = NULL;
	GRand* _tmp0_;
	gint* tab = NULL;
	gint* _tmp1_;
	gint tab_length1;
	gint _tab_size_;
	gint nb = 0;
	gint* _tmp8_;
	gint _tmp8__length1;
	gint* result;
	_tmp0_ = g_rand_new ();
	rand = _tmp0_;
	_tmp1_ = g_new0 (gint, size);
	tab = _tmp1_;
	tab_length1 = size;
	_tab_size_ = tab_length1;
	nb = 0;
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp2_ = FALSE;
			_tmp2_ = TRUE;
			while (TRUE) {
				GRand* _tmp4_;
				gint* _tmp5_;
				gint _tmp5__length1;
				if (!_tmp2_) {
					gint _tmp3_;
					i = i + 1;
					_tmp3_ = i;
				}
				_tmp2_ = FALSE;
				if (!(i != size)) {
					break;
				}
				_tmp4_ = rand;
				nb = (gint) g_rand_int_range (_tmp4_, (gint32) 1, (gint32) (size + 1));
				_tmp5_ = tab;
				_tmp5__length1 = tab_length1;
				if (_vala_int_array_contains (_tmp5_, _tmp5__length1, nb)) {
					gint _tmp6_;
					i = i - 1;
					_tmp6_ = i;
				} else {
					gint* _tmp7_;
					gint _tmp7__length1;
					_tmp7_ = tab;
					_tmp7__length1 = tab_length1;
					_tmp7_[i] = nb;
				}
			}
		}
	}
	_tmp8_ = tab;
	_tmp8__length1 = tab_length1;
	if (result_length1) {
		*result_length1 = _tmp8__length1;
	}
	result = _tmp8_;
	_g_rand_free0 (rand);
	return result;
}

