
package com.habzy.swig;

import android.os.Bundle;
import android.app.Activity;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends Activity {

    private static final String TAG = MainActivity.class.getSimpleName();
    TextView mView = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        Log.d(TAG, "===onCreate");
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mView = (TextView) findViewById(R.id.mText);
        
        // //First new.
        Circle mCircle = new Circle(10, new CircleCallback());
        mView.setText("The Circle's Area is " + mCircle.area());

        // Change radius. Will call CircleCallback.onChanged.
        Log.d(TAG, "===Before mCircle.setR(30)");
        mCircle.setR(30);
        Log.d(TAG, "===After  mCircle.setR(30)");
        
        CircleMgr mgr = CircleMgr.createMgr();
        mgr.add(new Circle(1, new CircleCallback()));
        mgr.add(mCircle);
        Circle circle= mgr.getFirstOBJ();
        
        Log.d(TAG, "===mgr.getFirstOBJ():"+circle.area());
    }

    private class CircleCallback extends Callback {
        /*
         * (non-Javadoc)
         * @see
         * com.example.swigdemo.Callback#onChanged(com.example.swigdemo.Shape)
         */
        @Override
        public void onChanged(Shape shape) {
            Log.d("CircleCallback", "===33333333333java-onChanged. area:" + shape.area());
        }
    }

}
