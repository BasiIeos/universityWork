(defun mytime (&optional (baseh 0) (basem 0))
   (let ((hh baseh) (mm basem))
      (labels
          ( ; local functions
              (set (h m)
                  (if (and (>= h 0) (< h 60) (>= m 0) (< m 60))
                     (block 'oktime
                         (setf hh h)
                         (setf mm m)
                         t)))
              (gethh () hh)
              (getmm () mm))
              (print () (format t "~A : ~A~%" hh mm))
          ; dispatcher
          (lambda (cmd &optional (arg1 0) (arg2 0))
              (cond
                 ((equalp cmd 'set) (set arg1 arg2))
                 ((equalp cmd 'gethh) (gethh))
                 ((equalp cmd 'getmm) (getmm))
                 ((equalp cmd ‘print) (print))
                 (t (format t "bad command~%")))))))
