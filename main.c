#include <gst/gst.h>

int main(int argc, char *argv[]) {
    GstElement *pipeline;
    GstBus *bus;
    GstMessage *msg;

    gst_init(&argc, &argv);

    if (argc != 2) {
        g_printerr("Usage: %s <video_file_path>\n", argv[0]);
        return -1;
    }

    gchar *video_path = argv[1];

    // Create pipeline using fpsdisplaysink for FPS overlay
    gchar *pipeline_desc = g_strdup_printf(
        "filesrc location=%s ! decodebin ! fpsdisplaysink video-sink=autovideosink text-overlay=true sync=false",
        video_path
    );

    GError *error = NULL;
    pipeline = gst_parse_launch(pipeline_desc, &error);
    g_free(pipeline_desc);

    if (!pipeline) {
        g_printerr("Error: Failed to create pipeline: %s\n", error->message);
        g_error_free(error);
        return -1;
    }

    gst_element_set_state(pipeline, GST_STATE_PLAYING);

    bus = gst_element_get_bus(pipeline);
    msg = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE,
                                     GST_MESSAGE_ERROR | GST_MESSAGE_EOS);

    if (msg != NULL) {
        GError *err;
        gchar *debug_info;

        if (GST_MESSAGE_TYPE(msg) == GST_MESSAGE_ERROR) {
            gst_message_parse_error(msg, &err, &debug_info);
            g_printerr("Error: %s\n", err->message);
            g_error_free(err);
            g_free(debug_info);
        } else if (GST_MESSAGE_TYPE(msg) == GST_MESSAGE_EOS) {
            g_print("Video playback finished.\n");
        }

        gst_message_unref(msg);
    }

    gst_object_unref(bus);
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);

    return 0;
}
