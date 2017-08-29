
#===============================================================================
# Makefile generated with fdlib.sh for pd lib builder
# Tue Aug 29 10:14:51 EDT 2017
# Author: Fede Camara Halac
# Email: fch226@nyu.edu
#===============================================================================

lib.name = fd_lib

class.sources = ./back/back.c ./cantor/cantor.c ./clifford/clifford.c ./connect/connect.c ./counter/counter.c ./crand/crand.c ./cuadratic/cuadratic.c ./define_loudspeakers/define_loudspeakers.c ./factor/factor.c ./fdm/fdm.c ./gausstwister/gausstwister.c ./glistinfo/glistinfo.c ./halton/halton.c ./henon/henon.c ./ipa/ipa.c ./irlog/irlog.c ./irpow/irpow.c ./irsqrt/irsqrt.c ./irsum/irsum.c ./list_fft/list_fft.c ./lorenz/lorenz.c ./lornorm/lornorm.c ./lorsig~/lorsig~.c ./lor~/lor~.c ./mainpath/mainpath.c ./mainscore/mainscore.c ./mandelbrot/mandelbrot.c ./minimax/minimax.c ./mtwister/mtwister.c ./parabola/parabola.c ./PdCon16~/PdCon16~.c ./pmtwister/pmtwister.c ./pointerlist/pointerlist.c ./prandom/prandom.c ./randy/randy.c ./reflect/reflect.c ./root/root.c ./scroll/scroll.c ./siginfo/siginfo.c ./sradio/sradio.c ./tracks2/tracks2.c ./txt2pd/ruinas.c ./txt2pd/txt2pd.c ./vbap/vbap.c

datafiles = ./!an_overview/an_overview-help.pd ./!msg/!msg-help.pd ./_fdblobvid/_fdblobvid-help.pd ./back/back-help.pd ./cantor/cantor-help.pd ./clifford/clifford-help.pd ./connect/connect-help.pd ./counter/counter-help.pd ./crand/crand-help.pd ./cuadratic/cuadratic-help.pd ./factor/factor-help.pd ./fd/__-help.pd ./fd/_bass-help.pd ./fd/_distor-help.pd ./fd/_legato-help.pd ./fd/_mbass-help.pd ./fd/_note-help.pd ./fd/_overview-help.pd ./fd/_snote-help.pd ./fd/_stick-help.pd ./fd/_tom-help.pd ./fd/_wood-help.pd ./fd_2bit/fd_2bit-help.pd ./fd_6x6/fd_6x6-help.pd ./fd_any2list/fd_any2list-help.pd ./fd_arcsin/fd_arcsin-help.pd ./fd_arcsin~/fd_arcsin~-help.pd ./fd_arg1/fd_arg1-help.pd ./fd_argc/fd_argc-help.pd ./fd_argv/fd_argv-help.pd ./fd_array2pix/fd_array2pix-help.pd ./fd_arrayautotrim/fd_arrayautotrim-help.pd ./fd_arraycopy/fd_arraycopy-help.pd ./fd_arraymorph/fd_arraymorph-help.pd ./fd_arraysort1/fd_arraysort1-help.pd ./fd_arraysort2/fd_arraysort2-help.pd ./fd_arraytrim/fd_arraytrim-help.pd ./fd_autopatch/fd_autopatch-help.pd ./fd_autopoly/fd_autopoly-help.pd ./fd_background/fd_background-help.pd ./fd_bang/fd_bang-help.pd ./fd_bangem/fd_bangem-help.pd ./fd_bark/fd_bark-help.pd ./fd_bark~/fd_bark~-help.pd ./fd_bigmyvu/fd_bigmyvu-help.pd ./fd_blackman/fd_blackman-help.pd ./fd_blackman~/fd_blackman~-help.pd ./fd_blob/fd_blob-help.pd ./fd_blobtracks/fd_blobtracks-help.pd ./fd_blobvid/fd_blobvid-help.pd ./fd_bufvid/fd_bufvid-help.pd ./fd_calm/fd_calm-help.pd ./fd_camara/fd_camara-help.pd ./fd_cauchy/fd_cauchy-help.pd ./fd_cauchy~/fd_cauchy~-help.pd ./fd_ceil/fd_ceil-help.pd ./fd_circle/fd_circle-help.pd ./fd_clarg/fd_clarg-help.pd ./fd_clicktrack/fd_clicktrack-help.pd ./fd_colorpicker/fd_colorpicker-help.pd ./fd_colortheme/fd_colortheme-help.pd ./fd_cosline~/fd_cosline~-help.pd ./fd_countdown/fd_countdown-help.pd ./fd_cputime/fd_cputime-help.pd ./fd_critical/fd_critical-help.pd ./fd_cuacua/fd_cuacua-help.pd ./fd_cubic/fd_cubic-help.pd ./fd_dacout/fd_dacout-help.pd ./fd_dataDroplet/fd_dataDroplet-help.pd ./fd_dataExp/fd_dataExp-help.pd ./fd_dataGui/fd_dataGui-help.pd ./fd_dataHann/fd_dataHann-help.pd ./fd_dataID/fd_dataID-help.pd ./fd_dataLine/fd_dataLine-help.pd ./fd_dataMorph/fd_dataMorph-help.pd ./fd_dataMorphArray/fd_dataMorphArray-help.pd ./fd_dataMorphGui/fd_dataMorphGui-help.pd ./fd_dataMorphWidth/fd_dataMorphWidth-help.pd ./fd_dataRand/fd_dataRand-help.pd ./fd_dataRead/fd_dataRead-help.pd ./fd_dataRead1/fd_dataRead1-help.pd ./fd_dataRead3/fd_dataRead3-help.pd ./fd_dataStoreGui/fd_dataStoreGui-help.pd ./fd_dataVis/fd_dataVis-help.pd ./fd_dataWalk/fd_dataWalk-help.pd ./fd_delit/fd_delit-help.pd ./fd_distributions/fd_distributions-help.pd ./fd_dory/fd_dory-help.pd ./fd_dsp/fd_dsp-help.pd ./fd_dsp-bang/fd_dsp-bang-help.pd ./fd_dspon/fd_dspon-help.pd ./fd_emap2/fd_emap2-help.pd ./fd_env/fd_env-help.pd ./fd_etareti/fd_etareti-help.pd ./fd_exp/fd_exp-help.pd ./fd_expo~/fd_expo~-help.pd ./fd_fftfilt/fd_fftfilt-help.pd ./fd_film2img/fd_film2img-help.pd ./fd_filt/fd_filt-help.pd ./fd_floor/fd_floor-help.pd ./fd_fm/fd_fm-help.pd ./fd_fmosc/fd_fmosc-help.pd ./fd_fromsig/fd_fromsig-help.pd ./fd_gauss/fd_gauss-help.pd ./fd_gauss~/fd_gauss~-help.pd ./fd_gem2feat/fd_gem2feat-help.pd ./fd_gembuf/fd_gembuf-help.pd ./fd_GEMbuffsize/fd_GEMbuffsize-help.pd ./fd_gemloop/fd_gemloop-help.pd ./fd_gemsphere/fd_gemsphere-help.pd ./fd_geomean/fd_geomean-help.pd ./fd_get-element/fd_get-element-help.pd ./fd_getfiles/fd_getfiles-help.pd ./fd_getid/fd_getid-help.pd ./fd_getsize/fd_getsize-help.pd ./fd_gr/fd_gr-help.pd ./fd_grain/fd_grain-help.pd ./fd_gscore/fd_gscore-help.pd ./fd_gt/fd_gt-help.pd ./fd_guiDelta/fd_guiDelta-help.pd ./fd_guiFont/fd_guiFont-help.pd ./fd_guiTemplate/fd_guiTemplate-help.pd ./fd_hann~/fd_hann~-help.pd ./fd_hopmsec/fd_hopmsec-help.pd ./fd_hradio/fd_hradio-help.pd ./fd_img2feat/fd_img2feat-help.pd ./fd_impulse/fd_impulse-help.pd ./fd_input/fd_input-help.pd ./fd_inputGui/fd_inputGui-help.pd ./fd_iterate/fd_iterate-help.pd ./fd_itpoint/fd_itpoint-help.pd ./fd_jumpv/fd_jumpv-help.pd ./fd_key/fd_key-help.pd ./fd_keycomb/fd_keycomb-help.pd ./fd_kinetica/fd_kinetica-help.pd ./fd_kp/fd_kp-help.pd ./fd_list-pointer/fd_list-pointer-help.pd ./fd_listout/fd_listout-help.pd ./fd_log/fd_log-help.pd ./fd_logistic/fd_logistic-help.pd ./fd_logistic~/fd_logistic~-help.pd ./fd_logo/fd_logo-help.pd ./fd_loop/fd_loop-help.pd ./fd_lorenz/fd_lorenz-help.pd ./fd_lorenz-expr/fd_lorenz-expr-help.pd ./fd_lorsig/fd_lorsig-help.pd ./fd_lspace/fd_lspace-help.pd ./fd_m-comb/fd_m-comb-help.pd ./fd_ma/fd_ma-help.pd ./fd_map/fd_map-help.pd ./fd_map2/fd_map2-help.pd ./fd_markfour/fd_markfour-help.pd ./fd_markov/fd_markov-help.pd ./fd_markov3/fd_markov3-help.pd ./fd_markov5/fd_markov5-help.pd ./fd_matrix-comb/fd_matrix-comb-help.pd ./fd_metro/fd_metro-help.pd ./fd_midiread/fd_midiread-help.pd ./fd_miller-gauss/fd_miller-gauss-help.pd ./fd_minimax/fd_minimax-help.pd ./fd_msecparse/fd_msecparse-help.pd ./fd_mtxdelit/fd_mtxdelit-help.pd ./fd_mtxout/fd_mtxout-help.pd ./fd_mult/fd_mult-help.pd ./fd_n!/fd_n!-help.pd ./fd_n=n-1/fd_n=n-1-help.pd ./fd_netreceive/fd_netreceive-help.pd ./fd_netsend/fd_netsend-help.pd ./fd_next/fd_next-help.pd ./fd_nonpulmonic/fd_nonpulmonic-help.pd ./fd_norep/fd_norep-help.pd ./fd_norm/fd_norm-help.pd ./fd_norm-abs/fd_norm-abs-help.pd ./fd_nouns/fd_nouns-help.pd ./fd_numkey/fd_numkey-help.pd ./fd_objcreator/fd_objcreator-help.pd ./fd_octaver/fd_octaver-help.pd ./fd_once/fd_once-help.pd ./fd_osc/fd_osc-help.pd ./fd_out/fd_out-help.pd ./fd_pan/fd_pan-help.pd ./fd_parsenum/fd_parsenum-help.pd ./fd_phatty/fd_phatty-help.pd ./fd_pix2list/fd_pix2list-help.pd ./fd_pix_shift/fd_pix_shift-help.pd ./fd_pixcrop/fd_pixcrop-help.pd ./fd_pixrecord/fd_pixrecord-help.pd ./fd_plot/fd_plot-help.pd ./fd_pno/fd_pno-help.pd ./fd_poisson/fd_poisson-help.pd ./fd_poisson~/fd_poisson~-help.pd ./fd_polea/fd_polea-help.pd ./fd_preset/fd_preset-help.pd ./fd_printer/fd_printer-help.pd ./fd_pshift/fd_pshift-help.pd ./fd_r/fd_r-help.pd ./fd_range/fd_range-help.pd ./fd_rbd/fd_rbd-help.pd ./fd_rec/fd_rec-help.pd ./fd_receive/fd_receive-help.pd ./fd_reflect/fd_reflect-help.pd ./fd_relocate/fd_relocate-help.pd ./fd_rexpo~/fd_rexpo~-help.pd ./fd_rgb/fd_rgb-help.pd ./fd_rgbcol/fd_rgbcol-help.pd ./fd_round/fd_round-help.pd ./fd_s-prob/fd_s-prob-help.pd ./fd_s-prob-5/fd_s-prob-5-help.pd ./fd_salvo/fd_salvo-help.pd ./fd_scales/fd_scales-help.pd ./fd_seltab/fd_seltab-help.pd ./fd_send/fd_send-help.pd ./fd_set-element/fd_set-element-help.pd ./fd_shader/fd_shader-help.pd ./fd_shift/fd_shift-help.pd ./fd_shuffle/fd_shuffle-help.pd ./fd_siginfo/fd_siginfo-help.pd ./fd_sin/fd_sin-help.pd ./fd_sinc/fd_sinc-help.pd ./fd_sinc~/fd_sinc~-help.pd ./fd_sinh/fd_sinh-help.pd ./fd_sinh~/fd_sinh~-help.pd ./fd_sp/fd_sp-help.pd ./fd_spat/fd_spat-help.pd ./fd_spigot/fd_spigot-help.pd ./fd_spigot3/fd_spigot3-help.pd ./fd_spline~/fd_spline~-help.pd ./fd_step/fd_step-help.pd ./fd_stopwatch/fd_stopwatch-help.pd ./fd_sum/fd_sum-help.pd ./fd_swap/fd_swap-help.pd ./fd_switch/fd_switch-help.pd ./fd_t-read/fd_t-read-help.pd ./fd_tabswitch/fd_tabswitch-help.pd ./fd_tempo-msec/fd_tempo-msec-help.pd ./fd_test-tone/fd_test-tone-help.pd ./fd_test8/fd_test8-help.pd ./fd_textsort2/fd_textsort2-help.pd ./fd_tglvis/fd_tglvis-help.pd ./fd_title/fd_title-help.pd ./fd_toroman/fd_toroman-help.pd ./fd_tovowel/fd_tovowel-help.pd ./fd_tracktopol/fd_tracktopol-help.pd ./fd_trapezoid~/fd_trapezoid~-help.pd ./fd_triangle~/fd_triangle~-help.pd ./fd_trunc2n/fd_trunc2n-help.pd ./fd_untext/fd_untext-help.pd ./fd_updown/fd_updown-help.pd ./fd_vibrato/fd_vibrato-help.pd ./fd_vidbuf/fd_vidbuf-help.pd ./fd_vidfft/fd_vidfft-help.pd ./fd_visera/fd_visera-help.pd ./fd_vu/fd_vu-help.pd ./fd_welch/fd_welch-help.pd ./fd_welch~/fd_welch~-help.pd ./fd_wielevy/fd_wielevy-help.pd ./fd_wielevy2/fd_wielevy2-help.pd ./fd_wind/fd_wind-help.pd ./fd_windows/fd_windows-help.pd ./fd_winreceive~/fd_winreceive~-help.pd ./fd_write/fd_write-help.pd ./fd_write1/fd_write1-help.pd ./fd_write2/fd_write2-help.pd ./fd_write5/fd_write5-help.pd ./fd_z12/fd_z12-help.pd ./fd_zero-crossing~/fd_zero-crossing~-help.pd ./fdm/fdm-help.pd ./gausstwister/gausstwister-help.pd ./gemvertexbuffer/gemvertexbuffer-help.pd ./glistinfo/glistinfo-help.pd ./halton/halton-help.pd ./henon/henon-help.pd ./ipa/ipa-help.pd ./irlog/irlog-help.pd ./irpow/irpow-help.pd ./irsqrt/irsqrt-help.pd ./irsum/irsum-help.pd ./list_fft/list_fft-help.pd ./lorenz/lorenz-help.pd ./lornorm/lornorm-help.pd ./lorsig~/lorsig~-help.pd ./lor~/lor~-help.pd ./mainpath/mainpath-help.pd ./mainscore/mainscore-help.pd ./mandelbrot/mandelbrot-help.pd ./minimax/minimax-help.pd ./mtwister/mtwister-help.pd ./parabola/parabola-help.pd ./PdCon16~/PdCon16~-help.pd ./pix_fft/pix_fft-help.pd ./pix_fft/pix_ifft-help.pd ./pix_fft/pix_mag-help.pd ./pix_fft/pix_phase-help.pd ./pix_fft/pix_shift-help.pd ./pix_fft2/pix_fft2-help.pd ./pix_fftfilt/pix_fftfilt-help.pd ./pix_ifft2/pix_ifft2-help.pd ./pix_morph/pix_morph-help.pd ./pix_shift/pix_shift-help.pd ./pix_turb/pix_turb-help.pd ./pmtwister/pmtwister-help.pd ./pointerlist/pointerlist-help.pd ./prandom/prandom-help.pd ./reflect/reflect-help.pd ./root/root-help.pd ./scroll/scroll-help.pd ./siginfo/siginfo-help.pd ./sradio/sradio-help.pd ./tracks2/tracks2-help.pd ./txt2pd/txt2pd-help.pd ./back/back-test.pd ./clifford/clifford-test.pd ./cuadratic/cuadratic-test.pd ./fd_env/fd_env-test.pd ./fd_gauss~/fd_gauss-test.pd ./fd_guiTemplate/fd_guiTemplate-test.pd ./fd_hradio/fd_hradio-test.pd ./fd_markfour/fd_markfour-test.pd ./fd_markov/fd_markov-test.pd ./fd_markov5/fd_markov5-test.pd ./fd_plot/fd_plot-test.pd ./halton/halton-test.pd ./lorenz/lorenz-test.pd ./lornorm/lorenz-test.pd ./minimax/minimax-test.pd ./reflect/reflect-test.pd ./sradio/sradio-test.pd 

include pd-lib-builder/Makefile.pdlibbuilder

#===============================================================================

