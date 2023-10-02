package com.aniketjain.weatherapp.toast;

import android.content.Context;

import com.aniketjain.roastedtoast.Toasty;
import com.aniketjain.weatherapp.R;

public class Toaster {
    public static void successToast(Context context, String msg) {
        Toasty.custom(
                context,
                msg,
                R.drawable.ic_baseline_check_24,
                "#454B54",
                14,
                "#EEEEEE");
    }

    public static void errorToast(Context context, String msg) {
        Toasty.custom(
                context,
                msg,
                R.drawable.ic_baseline_error_outline_24,
                "#454B54",
                14,
                "#EEEEEE");
    }
}
