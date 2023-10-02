package com.aniketjain.weatherapp.update;

import android.content.Context;

import com.aniketjain.weatherapp.R;

public class UpdateUI {

    public static String getIconID(int condition, long update_time, long sunrise, long sunset) {
        if (condition >= 200 && condition <= 232)
            return "thunderstorm";
        else if (condition >= 300 && condition <= 321)
            return "drizzle";
        else if (condition >= 500 && condition <= 531)
            return "rain";
        else if (condition >= 600 && condition <= 622)
            return "snow";
        else if (condition >= 701 && condition <= 781)
            return "wind";
        else if (condition == 800) {
            if (update_time >= sunrise && update_time <= sunset)
                return "clear_day";
            else
                return "clear_night";
        } else if (condition == 801) {
            if (update_time >= sunrise && update_time <= sunset)
                return "few_clouds_day";
            else
                return "few_clouds_night";
        } else if (condition == 802)
            return "scattered_clouds";
        else if (condition == 803 || condition == 804)
            return "broken_clouds";
        return null;
    }

    public static String TranslateDay(String dayToBeTranslated, Context context) {
        switch (dayToBeTranslated.trim()) {
            case "Monday":
                return context.getResources().getString(R.string.monday);
            case "Tuesday":
                return context.getResources().getString(R.string.tuesday);
            case "Wednesday":
                return context.getResources().getString(R.string.wednesday);
            case "Thursday":
                return context.getResources().getString(R.string.thursday);
            case "Friday":
                return context.getResources().getString(R.string.friday);
            case "Saturday":
                return context.getResources().getString(R.string.saturday);
            case "Sunday":
                return context.getResources().getString(R.string.sunday);
        }
        return dayToBeTranslated;
    }
}
