/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package org.cocos2dx.extbeatanni;

import org.cocos2dx.lib.Cocos2dxActivity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.WindowManager;

public class ExtremeBeatAnnihilation extends Cocos2dxActivity{

	private static final int REQUEST_SONG_FILE = 0;
	private static Object activity;
	private String chosenSong;
	
	public static Object getObject()
	{
		Log.i("cppCall", "Returning activity");
		return activity;
	}
	
	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		activity = this;
		getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
	}
	
	public String startupFileExplore()
	{
		try
		{
 			Intent fileExploreIntent = new Intent(ExtremeBeatAnnihilation.this, FileExplore.class);
			
			if(fileExploreIntent != null)
			{
				startActivityForResult(fileExploreIntent, REQUEST_SONG_FILE);
			}
			else 
			{
				Log.d("Extreme Beat Annihilation", "FileExploreIntent null\n");
			}
		}
		catch(Exception e)
		{
			Log.d("Extreme", "Error" + e.getMessage());
		}

		return chosenSong;
	}
	
	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data)
	{
	    if (resultCode == Activity.RESULT_OK && requestCode == REQUEST_SONG_FILE)
	    {
	        chosenSong = data.getStringExtra("Song File");
	    }
	}
	
    static {
         System.loadLibrary("game");
    }
}
