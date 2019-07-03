/*
 * Copyright (c) 2019. Parrot Faurecia Automotive S.A.S. All rights reserved.
 */

package com.example.ts.javatoc;

import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.Signature;
import android.content.pm.SigningInfo;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        try {
            PackageInfo packageInfo = getPackageManager().getPackageInfo(getPackageName(), PackageManager
                    .GET_SIGNATURES);
            Signature[] signatures = packageInfo.signatures;
            Log.e("---", "--signatures---" + signatures[0].toCharsString());
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        Helper helper = new Helper();
        Log.e("---", "--getJavaPackage---" + helper.getJavaPackage(this));
        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native String checkSignal(Context context,String pm);


}
