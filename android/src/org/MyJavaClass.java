package org;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.content.Context;

public class MyJavaClass{
    public static void SendLoginSuccessBroadcast(Context context) {
        Intent intent =new Intent("android.intent.action.KEY_STATUS");
        intent.putExtra("keyStatus","ONLine");
        context.sendBroadcast(intent);
    }

    public static void SendOfflineBroadcast(Context context) {
        Intent intent =new Intent("android.intent.action.KEY_STATUS");
        intent.putExtra("keyStatus","OFFLine");
        context.sendBroadcast(intent);
    }
}
