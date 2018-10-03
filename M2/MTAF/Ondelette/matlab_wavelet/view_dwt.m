function varargout = view_dwt(varargin)
% VIEW_DWT M-file for view_dwt.fig
%      VIEW_DWT, by itself, creates a new VIEW_DWT or raises the existing
%      singleton*.
%
%      H = VIEW_DWT returns the handle to a new VIEW_DWT or the handle to
%      the existing singleton*.
%
%      VIEW_DWT('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in VIEW_DWT.M with the given input arguments.
%
%      VIEW_DWT('Property','Value',...) creates a new VIEW_DWT or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before view_dwt_OpeningFunction gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to view_dwt_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help view_dwt

% Last Modified by GUIDE v2.5 29-Sep-2009 15:24:13

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @view_dwt_OpeningFcn, ...
                   'gui_OutputFcn',  @view_dwt_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before view_dwt is made visible.
function view_dwt_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to view_dwt (see VARARGIN)

% Choose default command line output for view_dwt
handles.output = hObject;

N=128;
W=zeros(128,128);
handles.W=W;
handles.R=W;
handles.N=N;

options=struct('wavelet_type','biorthogonal','vm',3);
handles.options = options;
handles.type = 2;
set(handles.popupmenu1,'Value',handles.type);

handles.invalidW = 0;

handles.Jmin=7-3;

% Update handles structure
guidata(hObject, handles);

redraw(hObject,[],handles);


% UIWAIT makes view_dwt wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = view_dwt_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on mouse press over axes background.
function axes1_ButtonDownFcn(hObject, eventdata, handles)
% hObject    handle to axes1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

function axes2_ButtonDownFcn(hObject, eventdata, handles)


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


N=handles.N;
Jmin=handles.Jmin;

set(handles.text1,'String','Sélectionnez un coefficient d''ondelette...');

axes(handles.axes1);
[j,i]=ginput(1);
j=max(1,min(N,round(j)));
i=max(1,min(N,round(i)));
W=handles.W;%zeros(N,N);
W(i,j)=255;

set(handles.text1,'String','');

handles.W=W;
guidata(hObject, handles);
redraw(hObject,[],handles);

% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

N=handles.N;
Jmin=handles.Jmin;

set(handles.text1,'String','Tracez un polygone dans un cadran...');

axes(handles.axes1);
W=handles.W;%zeros(N,N);
show_wavelet(W,Jmin,'real',1);
W=roipoly*255;

set(handles.text1,'String','');

W=W+handles.W;

handles.W=W;
guidata(hObject, handles);
redraw(hObject,[],handles);

% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

N=handles.N;
Jmin=handles.Jmin;

set(handles.text2,'String','Tracez un polygone dans l''image...');

axes(handles.axes2);
I=zeros(N,N);
I=roipoly*255;

set(handles.text2,'String','');

[W]=perform_wavelet_transform(I, Jmin, 1, handles.options);
handles.invalidW = 1;

handles.W=W;
guidata(hObject, handles);
redraw(hObject,[],handles);


% --- Executes on button press in pushbutton4.
function pushbutton4_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



function redraw(hObject, eventdata, handles)

W=handles.W;
Jmin=handles.Jmin;

axes(handles.axes1);
show_wavelet(W,Jmin,'real',1);
axis('image');
drawnow

[R]=perform_wavelet_transform(W, Jmin, -1, handles.options);

handles.R = R;
guidata(hObject,handles);

axes(handles.axes2);
imagesc(R);
colormap(gray(256));
%colorbar;
drawnow







% --- Executes on button press in pushbutton5.
function pushbutton5_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


handles.W=zeros(handles.N);
guidata(hObject, handles);
redraw(hObject,[],handles);


% --- Executes on button press in pushbutton6.
function pushbutton6_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

[filename, pathname] = uigetfile({'*.jpg;*.png;*.gif;*.bmp', 'Image file'; ...
    '*.*','Any file'});
if isequal(filename,0) || isequal(pathname,0)
    disp('Image import canceled...')
else
    name=fullfile(pathname, filename);
    disp(['Importing image ', name,'...'])
    
    I=imread(name);
    if (ndims(I)==3)
        I=double(rgb2gray(I));
    else
        I=double(I);
    end
    N=handles.N;
    I=imresize(I,[N,N],'bicubic');
    
    Jmin=handles.Jmin;
    [W]=perform_wavelet_transform(I, Jmin, 1, handles.options);

    handles.invalidW = 1;
    
    handles.W=W;
    guidata(hObject, handles);
    redraw(hObject,[],handles);
end



% --- Executes on button press in pushbutton7.
function pushbutton7_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

assignin('base','W',handles.W);
assignin('base','R',handles.R);

disp('Images exportées dans le workspace général');
disp('et enregistrées dans les fichiers export-*.png');
disp('>> whos W R');
evalin('base','whos W R');

Wout = show_wavelet(handles.W,handles.Jmin,'real', 1);
Rout = (handles.R-min(handles.R(:))) / (max(handles.R(:))-min(handles.R(:))+eps);

imwrite(Wout, 'export-W.png');
imwrite(Rout, 'export-R.png');


% --- Executes on selection change in popupmenu1.
function popupmenu1_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = get(hObject,'String') returns popupmenu1 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu1

old_options = handles.options;

v=get(hObject,'Value');
switch (v)
    case 1
        options=struct('wavelet_type','haar');
        handles.options = options;
    case 2
        options=struct('wavelet_type','biorthogonal','vm',3);
        handles.options = options;
end

if (handles.invalidW)
    handles.W = zeros(128);
    handles.R = zeros(128);
else
    handles.R = perform_wavelet_transform(handles.W, handles.Jmin, -1, options);
end

guidata(hObject, handles);
redraw(hObject,[],handles);

% --- Executes during object creation, after setting all properties.
function popupmenu1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


