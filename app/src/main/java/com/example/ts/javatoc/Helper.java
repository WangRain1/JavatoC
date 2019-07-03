/*
 * Copyright (c) 2019. Parrot Faurecia Automotive S.A.S. All rights reserved.
 */

package com.example.ts.javatoc;

import android.content.Context;

public class Helper {

    public native String getJavaPackage(Context context);

    public String getPackage(Context context){

        return context.getPackageName();
    }
}
